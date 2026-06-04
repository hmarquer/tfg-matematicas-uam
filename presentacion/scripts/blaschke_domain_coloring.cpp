// Interactive domain coloring on the Riemann sphere using OpenGL shaders.

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <array>
#include <cmath>
#include <cstdio>
#include <vector>

struct Vec3 {
    float x;
    float y;
    float z;
};

struct Mat4 {
    float m[16];
};

static Mat4 mat4_identity() {
    Mat4 out = {};
    out.m[0] = 1.0f;
    out.m[5] = 1.0f;
    out.m[10] = 1.0f;
    out.m[15] = 1.0f;
    return out;
}

static Mat4 mat4_mul(const Mat4 &a, const Mat4 &b) {
    Mat4 out = {};
    for (int col = 0; col < 4; ++col) {
        for (int row = 0; row < 4; ++row) {
            out.m[col * 4 + row] =
                a.m[0 * 4 + row] * b.m[col * 4 + 0] +
                a.m[1 * 4 + row] * b.m[col * 4 + 1] +
                a.m[2 * 4 + row] * b.m[col * 4 + 2] +
                a.m[3 * 4 + row] * b.m[col * 4 + 3];
        }
    }
    return out;
}

static Vec3 vec3_sub(const Vec3 &a, const Vec3 &b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

static Vec3 vec3_cross(const Vec3 &a, const Vec3 &b) {
    return {
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x,
    };
}

static float vec3_dot(const Vec3 &a, const Vec3 &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

static Vec3 vec3_norm(const Vec3 &v) {
    const float len = std::sqrt(vec3_dot(v, v));
    if (len <= 0.0f) {
        return {0.0f, 0.0f, 0.0f};
    }
    return {v.x / len, v.y / len, v.z / len};
}

static Mat4 mat4_look_at(const Vec3 &eye, const Vec3 &center, const Vec3 &up) {
    Vec3 f = vec3_norm(vec3_sub(center, eye));
    Vec3 s = vec3_norm(vec3_cross(f, up));
    Vec3 u = vec3_cross(s, f);

    Mat4 out = mat4_identity();
    out.m[0] = s.x;
    out.m[1] = s.y;
    out.m[2] = s.z;
    out.m[4] = u.x;
    out.m[5] = u.y;
    out.m[6] = u.z;
    out.m[8] = -f.x;
    out.m[9] = -f.y;
    out.m[10] = -f.z;
    out.m[12] = -vec3_dot(s, eye);
    out.m[13] = -vec3_dot(u, eye);
    out.m[14] = vec3_dot(f, eye);
    return out;
}

static Mat4 mat4_perspective(float fovy_rad, float aspect, float near_z, float far_z) {
    const float f = 1.0f / std::tan(fovy_rad * 0.5f);
    Mat4 out = {};
    out.m[0] = f / aspect;
    out.m[5] = f;
    out.m[10] = (far_z + near_z) / (near_z - far_z);
    out.m[11] = -1.0f;
    out.m[14] = (2.0f * far_z * near_z) / (near_z - far_z);
    return out;
}

static Mat4 mat4_rotate_y(float angle) {
    Mat4 out = mat4_identity();
    const float c = std::cos(angle);
    const float s = std::sin(angle);
    out.m[0] = c;
    out.m[2] = -s;
    out.m[8] = s;
    out.m[10] = c;
    return out;
}

static Mat4 mat4_rotate_x(float angle) {
    Mat4 out = mat4_identity();
    const float c = std::cos(angle);
    const float s = std::sin(angle);
    out.m[5] = c;
    out.m[6] = s;
    out.m[9] = -s;
    out.m[10] = c;
    return out;
}

static void glfw_error_callback(int code, const char *desc) {
    std::fprintf(stderr, "GLFW error %d: %s\n", code, desc);
}

static GLuint compile_shader(GLenum type, const char *source) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    GLint ok = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &ok);
    if (!ok) {
        GLint len = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
        std::vector<char> log(len);
        glGetShaderInfoLog(shader, len, nullptr, log.data());
        std::fprintf(stderr, "Shader compile error: %s\n", log.data());
        glDeleteShader(shader);
        return 0;
    }
    return shader;
}

static GLuint link_program(GLuint vs, GLuint fs) {
    GLuint program = glCreateProgram();
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);

    GLint ok = 0;
    glGetProgramiv(program, GL_LINK_STATUS, &ok);
    if (!ok) {
        GLint len = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);
        std::vector<char> log(len);
        glGetProgramInfoLog(program, len, nullptr, log.data());
        std::fprintf(stderr, "Program link error: %s\n", log.data());
        glDeleteProgram(program);
        return 0;
    }
    return program;
}

static void build_sphere_mesh(int stacks, int slices,
                              std::vector<float> &vertices,
                              std::vector<unsigned int> &indices) {
    const float pi = 3.14159265358979323846f;
    vertices.clear();
    indices.clear();

    for (int i = 0; i <= stacks; ++i) {
        const float v = static_cast<float>(i) / static_cast<float>(stacks);
        const float theta = v * pi;
        const float st = std::sin(theta);
        const float ct = std::cos(theta);
        for (int j = 0; j <= slices; ++j) {
            const float u = static_cast<float>(j) / static_cast<float>(slices);
            const float phi = u * 2.0f * pi;
            const float sp = std::sin(phi);
            const float cp = std::cos(phi);
            const float x = st * cp;
            const float y = st * sp;
            const float z = ct;
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);
        }
    }

    for (int i = 0; i < stacks; ++i) {
        for (int j = 0; j < slices; ++j) {
            const unsigned int row1 = i * (slices + 1);
            const unsigned int row2 = (i + 1) * (slices + 1);

            indices.push_back(row1 + j);
            indices.push_back(row2 + j);
            indices.push_back(row1 + j + 1);

            indices.push_back(row2 + j);
            indices.push_back(row2 + j + 1);
            indices.push_back(row1 + j + 1);
        }
    }
}

int main() {
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) {
        std::fprintf(stderr, "Failed to initialize GLFW.\n");
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(900, 900, "Blaschke Riemann Sphere", nullptr, nullptr);
    if (!window) {
        std::fprintf(stderr, "Failed to create GLFW window.\n");
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::fprintf(stderr, "Failed to initialize GLEW.\n");
        glfwTerminate();
        return 1;
    }

    const char *vertex_src = R"GLSL(
#version 330 core
layout(location = 0) in vec3 a_pos;

uniform mat4 u_mvp;
uniform mat4 u_model;

out vec3 v_normal;

void main() {
    v_normal = normalize((u_model * vec4(a_pos, 0.0)).xyz);
    gl_Position = u_mvp * vec4(a_pos, 1.0);
}
)GLSL";

    const char *fragment_src = R"GLSL(
#version 330 core
in vec3 v_normal;
out vec4 FragColor;

uniform int u_zero_count;
uniform vec2 u_zeros[8];
uniform int u_use_mod_value;
uniform int u_use_checkerboard;

const float PI = 3.14159265358979323846;

vec2 c_conj(vec2 a) {
    return vec2(a.x, -a.y);
}

vec2 c_mul(vec2 a, vec2 b) {
    return vec2(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}

vec2 c_div(vec2 a, vec2 b) {
    float denom = dot(b, b);
    if (denom <= 0.0) {
        return vec2(0.0, 0.0);
    }
    return c_mul(a, c_conj(b)) / denom;
}

float polar_checkerboard(vec2 w) {
    float r = max(length(w), 1e-6);
    float theta = atan(w.y, w.x);
    float ang = (theta + PI) / (2.0 * PI);

    float r_idx = fract(log2(r / 0.25));
    float ang_idx = fract(ang * 10.0);
    float checker = r_idx * ang_idx;
    float strength = 0.2;
    return 1.0 - strength + 2.0 * strength * checker;
}

vec3 hsv2rgb(vec3 c) {
    vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
    vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}

void main() {
    vec3 n = normalize(v_normal);
    float denom = max(1.0 - n.z, 1e-4);
    vec2 z = n.xy / denom;

    vec2 f = vec2(1.0, 0.0);
    for (int i = 0; i < u_zero_count; ++i) {
        vec2 zk = u_zeros[i];
        vec2 num = z - zk;
        vec2 den = vec2(1.0, 0.0) - c_mul(c_conj(zk), z);
        f = c_mul(f, c_div(num, den));
    }

    float arg = atan(f.y, f.x);
    float mod = length(f);
    float hue = (arg + PI) / (2.0 * PI);
    float value = 1.0;
    if (u_use_mod_value != 0) {
        value = 1.0 - 1.0 / (1.0 + log(1.0 + mod));
    }
    float sat = clamp(0.85 + 0.15 * tanh(mod), 0.0, 1.0);

    vec3 rgb = hsv2rgb(vec3(hue, sat, value));
    if (u_use_checkerboard != 0) {
        float check = polar_checkerboard(f);
        rgb = clamp(rgb * check, 0.0, 1.0);
    }

    FragColor = vec4(rgb, 1.0);
}
)GLSL";

    GLuint vs = compile_shader(GL_VERTEX_SHADER, vertex_src);
    if (!vs) {
        glfwTerminate();
        return 1;
    }
    GLuint fs = compile_shader(GL_FRAGMENT_SHADER, fragment_src);
    if (!fs) {
        glDeleteShader(vs);
        glfwTerminate();
        return 1;
    }
    GLuint program = link_program(vs, fs);
    glDeleteShader(vs);
    glDeleteShader(fs);
    if (!program) {
        glfwTerminate();
        return 1;
    }

    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    build_sphere_mesh(120, 240, vertices, indices);

    GLuint vao = 0;
    GLuint vbo = 0;
    GLuint ebo = 0;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(),
                 GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

    glBindVertexArray(0);

    const std::array<Vec3, 3> zeros = {
        Vec3{0.2f, 0.4f, 0.0f},
        Vec3{-0.35f, 0.25f, 0.0f},
        Vec3{0.55f, -0.2f, 0.0f},
    };

    const int use_mod_value = 0;
    const int use_checkerboard = 1;

    float zero_data[16] = {};
    for (size_t i = 0; i < zeros.size(); ++i) {
        zero_data[i * 2 + 0] = zeros[i].x;
        zero_data[i * 2 + 1] = zeros[i].y;
    }

    glEnable(GL_DEPTH_TEST);

    glUseProgram(program);
    GLint mvp_loc = glGetUniformLocation(program, "u_mvp");
    GLint model_loc = glGetUniformLocation(program, "u_model");
    GLint zeros_loc = glGetUniformLocation(program, "u_zeros");
    GLint zero_count_loc = glGetUniformLocation(program, "u_zero_count");
    GLint use_mod_loc = glGetUniformLocation(program, "u_use_mod_value");
    GLint use_checker_loc = glGetUniformLocation(program, "u_use_checkerboard");

    glUniform1i(zero_count_loc, static_cast<int>(zeros.size()));
    glUniform1i(use_mod_loc, use_mod_value);
    glUniform1i(use_checker_loc, use_checkerboard);
    glUniform2fv(zeros_loc, 8, zero_data);

    while (!glfwWindowShouldClose(window)) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }

        int width = 0;
        int height = 0;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        glClearColor(0.02f, 0.02f, 0.02f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        const float aspect = (height > 0) ? static_cast<float>(width) / height : 1.0f;
        const float time = static_cast<float>(glfwGetTime());

        Mat4 model = mat4_mul(mat4_rotate_y(time * 0.25f), mat4_rotate_x(-0.4f));
        Mat4 view = mat4_look_at({0.0f, 0.0f, 3.1f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f});
        Mat4 proj = mat4_perspective(45.0f * 3.14159265358979323846f / 180.0f, aspect, 0.1f, 20.0f);
        Mat4 mvp = mat4_mul(mat4_mul(proj, view), model);

        glUseProgram(program);
        glUniformMatrix4fv(mvp_loc, 1, GL_FALSE, mvp.m);
        glUniformMatrix4fv(model_loc, 1, GL_FALSE, model.m);

        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, nullptr);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteBuffers(1, &ebo);
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
    glDeleteProgram(program);

    glfwTerminate();
    return 0;
}
