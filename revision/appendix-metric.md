# Revisión — Apéndice: Resultados auxiliares sobre espacios métricos

## Bloque 0 — Definiciones de métrica y espacio métrico

- **Líneas:** [1–18](../appendix-metric.tex#L1-L18)
- **Estado:** revisado

**Checklist de revisión:**
- [x] [ORT] Ortografía y tipografía
- [x] [RED] Redacción y estilo
- [x] [NOT] Notación matemática
- [x] [MAT] Errores matemáticos
- [x] [REF] Referencias y estructura
- [x] [TEX] LaTeX y formato
- [x] [MEJ] Mejoras de presentación

**Comentarios:**

---

## Bloque 1 — Convergencia uniforme y continuidad uniforme

- **Líneas:** [20–59](../appendix-metric.tex#L20-L59)
- **Estado:** revisado

**Checklist de revisión:**
- [x] [ORT] Ortografía y tipografía
- [x] [RED] Redacción y estilo
- [x] [NOT] Notación matemática
- [x] [MAT] Errores matemáticos
- [x] [REF] Referencias y estructura
- [x] [TEX] LaTeX y formato
- [x] [MEJ] Mejoras de presentación

**Comentarios:**

---

## Bloque 2 — Combinaciones y envolturas convexas

- **Líneas:** [61–81](../appendix-metric.tex#L61-L81)
- **Estado:** revisado

**Checklist de revisión:**
- [x] [ORT] Ortografía y tipografía
- [x] [RED] Redacción y estilo
- [x] [NOT] Notación matemática
- [x] [MAT] Errores matemáticos
- [x] [REF] Referencias y estructura
- [x] [TEX] LaTeX y formato
- [x] [MEJ] Mejoras de presentación

**Comentarios:**

---

## Bloque 3 — Teorema de Stone–Weierstrass en $\mathbb{T}$

- **Líneas:** [83–90](../appendix-metric.tex#L83-L90)
- **Estado:** revisado

**Checklist de revisión:**
- [x] [ORT] Ortografía y tipografía
- [x] [RED] Redacción y estilo
- [x] [NOT] Notación matemática
- [x] [MAT] Errores matemáticos
- [x] [REF] Referencias y estructura
- [x] [TEX] LaTeX y formato
- [x] [MEJ] Mejoras de presentación

**Comentarios:**

---

## Comentarios generales

**Contenido y cobertura**
1. El apéndice mezcla temas que no guardan relación directa con espacios métricos: definiciones básicas (métrica, espacio métrico), convergencia uniforme, combinaciones convexas y el teorema de Stone–Weierstrass en el toro. **Sugerencia:** Separar en dos apéndices temáticos: uno solo de espacios métricos (definiciones, convergencia uniforme, continuidad uniforme) y otro de análisis convexo/Fourier (combinaciones convexas, envoltura convexa, Stone–Weierstrass), tal como indican los comentarios `%ORDENAR` ya presentes.
2. El teorema de Stone–Weierstrass (líneas 85–90) aparece sin contexto ni justificación dentro del apéndice; además, su enunciado omite definir el espacio $\mathcal{C}(\mathbb{T})$ (funciones continuas sobre el toro) y la norma bajo la que se toma el máximo. **Sugerencia:** Añadir una breve nota aclaratoria sobre $\mathcal{C}(\mathbb{T})$ y la norma del supremo, o mover el teorema al capítulo donde se utiliza.

**Estructura y organización**
1. No hay sección 3: el teorema de Stone–Weierstrass queda colgado tras la sección 2, interrumpiendo la estructura. **Sugerencia:** Asignarle una sección propia (p. ej., §3 «Teorema de aproximación de Stone–Weierstrass») o reposicionarlo según los comentarios `%ORDENAR` existentes.
2. Las proposiciones de combinaciones/envolturas convexas (secciones 2) son nociones de álgebra lineal/geometría convexa, no de espacios métricos. **Sugerencia:** Trasladarlas a un apéndice sobre espacios vectoriales normados o análisis convexo.
3. Falta un párrafo introductorio al inicio del apéndice que explicite su propósito y alcance. **Sugerencia:** Redactar 2–3 líneas que sitúen al lector sobre qué resultados se recogen y por qué son auxiliares para el resto del trabajo.

**Claridad y rigor**
1. En la definición de continuidad uniforme (línea 32) se restringe el dominio a $U \subset X$ abierto; la continuidad uniforme puede definirse sobre cualquier subconjunto, no solo abiertos. **Sugerencia:** Eliminar la condición «con $U$ abierto» o justificar por qué se requiere en este contexto.
2. En la demostración de la Proposición 1 (línea 42), se escoge $N$ tal que $d_Y(f_N(x), f(x)) < \varepsilon/3$ para todo $x \in X$, lo cual es correcto por convergencia uniforme, pero convendría indicar explícitamente que la convergencia uniforme da esa cota independiente de $x$. **Sugerencia:** Añadir una breve acotación «por convergencia uniforme» para mayor claridad pedagógica.
3. El enunciado de Stone–Weierstrass usa $\max_{\xi\in\mathbb{T}}$ sin especificar la norma; en $\mathcal{C}(\mathbb{T})$ el máximo coincide con la norma del supremo por compacidad, pero conviene aclararlo. **Sugerencia:** Escribir $\displaystyle\max_{\xi\in\mathbb{T}}|\cdot| = \|\cdot\|_\infty$ o añadir un comentario.

**Estilo y coherencia global**
1. El apéndice mantiene un estilo matemático correcto y las macros definidas (`\appl`, `\exhyperref`, `\we`, `\tex`) se usan con coherencia. Sin embargo, las etiquetas `\label` dentro de los ítems de enumeración (p. ej., `\label{defn:metrica:positividad}`) son innecesarias si no se referencian individualmente. **Sugerencia:** Revisar si esas etiquetas se usan realmente; si no, eliminarlas para simplificar.
2. La presencia de comentarios `%ORDENAR` en el código fuente indica que el apéndice está en fase de reestructuración. **Sugerencia:** Resolver esas tareas pendientes antes de la versión final para que el texto quede limpio.
3. La extensión del apéndice (90 líneas) es adecuada para un material auxiliar, pero la heterogeneidad temática resta cohesión. **Sugerencia:** Limitar el apéndice a nociones estrictamente métricas (definiciones, convergencia uniforme, continuidad uniforme) y mover el resto a otros anexos.
