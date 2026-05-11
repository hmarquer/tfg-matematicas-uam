## Bloque 0 — Introducción del capítulo

- **Archivo:** [../chap3.tex](../chap3.tex)
- **Líneas:** [L1-L2](../chap3.tex#L1-L2)
- **Estado:** revisado — sin errores
- **Comentarios:**
  - Sin observaciones.

## Bloque 1 — Definición y propiedades básicas

- **Archivo:** [../chap3.tex](../chap3.tex)
- **Líneas:** [L3-L44](../chap3.tex#L3-L44)
- **Estado:** revisado — corregido
<!-- - **Comentarios:**
  1. [TEX] Línea [L16-L18](../chap3.tex#L16-L18) — Entorno `obs` comentado pero el contenido queda activo. **Corrección sugerida:** descomentar el entorno completo o comentar también el contenido.
  2. [TEX] Línea [L20-L24](../chap3.tex#L20-L24) — Mismo problema con el segundo `obs`. **Corrección sugerida:** alinear los comentarios con el contenido o reactivar el entorno.
  3. [ORT] Línea [L17](../chap3.tex#L17) — “si, y sólo si,”. **Corrección sugerida:** “si y sólo si,”.
  4. [MAT] Línea [L38](../chap3.tex#L38) — Inconsistencia en la fórmula de reflexión: aparece $\bar{B(\bar{z})}$ en lugar de $\bar{B(1/\bar{z})}$. **Corrección sugerida:** usar $\sfrac{1}{\bar{B\left(\sfrac{1}{\bar{z}}\right)}}$. -->

## Bloque 2 — Caracterización de los productos finitos de Blaschke

- **Archivo:** [../chap3.tex](../chap3.tex)
- **Líneas:** [L45-L83](../chap3.tex#L45-L83)
- **Estado:** revisado — corregido
<!-- - **Comentarios:**
  1. [ORT] Línea [L61](../chap3.tex#L61) — Concordancia: “curva-cerrada … cerrado”. **Corrección sugerida:** “curva-cerrada … cerrada”.
  2. [RED] Línea [L65](../chap3.tex#L65) — “denotar al número” incorrecto. **Corrección sugerida:** “denotar el número”.
  3. [MAT] Línea [L77](../chap3.tex#L77) — El principio de identidad no justifica finitud. **Corrección sugerida:** aclarar que los ceros son aislados y, como $f$ es continua en $\bar{\mathbb{D}}$ y $|f|=1$ en $\mathbb{T}$, el conjunto de ceros es compacto y discreto, luego finito. -->

## Bloque 3 — Unicidad y no unicidad

- **Archivo:** [../chap3.tex](../chap3.tex)
- **Líneas:** [L84-L152](../chap3.tex#L84-L152)
- **Estado:** revisado — con observaciones
- **Comentarios:**
  1. [MAT] Línea [L93](../chap3.tex#L93) — Se asume $B_1(z)=B_2(z)$ para $z$ arbitrario sin justificarlo. **Corrección sugerida:** reformular la prueba con $R(z)=B_1(z)/B_2(z)$ y usar la hipótesis solo en los $w_k$.
  2. [TEX] Línea [L116](../chap3.tex#L116) — “$\im H$” no es estándar. **Corrección sugerida:** “$\Im H$”.
  3. [ORT] Línea [L148](../chap3.tex#L148) — “poque”. **Corrección sugerida:** “porque”.

## Bloque 4 — Valencia de los productos finitos de Blaschke

- **Archivo:** [../chap3.tex](../chap3.tex)
- **Líneas:** [L153-L266](../chap3.tex#L153-L266)
- **Estado:** revisado — con observaciones
- **Comentarios:**
  1. [RED] Línea [L168](../chap3.tex#L168) — Redacción cargada. **Corrección sugerida:** dividir y simplificar la frase inicial.
  2. [NOT] Línea [L168](../chap3.tex#L168) — $\Omega$ no está definido. **Corrección sugerida:** sustituir por $D(0,R)$ o definir $\Omega$ antes.
  3. [MAT] Línea [L186](../chap3.tex#L186)-[L190](../chap3.tex#L190) — La igualdad de derivada logarítmica falla en los ceros de $B$. **Corrección sugerida:** restringir a $\mathbb{D}\setminus\{z_1,\dots,z_n\}$.
  4. [NOT] Línea [L221](../chap3.tex#L221)-[L223](../chap3.tex#L223) — Se usa $\mathcal{B}$ en lugar de $\mathscr{B}$. **Corrección sugerida:** unificar la notación.

## Bloque 5 — Productos de Blaschke como funciones racionales

- **Archivo:** [../chap3.tex](../chap3.tex)
- **Líneas:** [L267-L391](../chap3.tex#L267-L391)
- **Estado:** revisado — con observaciones
- **Comentarios:**
  1. [MAT] Línea [L296](../chap3.tex#L296) — Condición de igualdad incorrecta: depende de $\alpha_0$, no de $\alpha_n$. **Corrección sugerida:** “se cumple si y solo si $\alpha_0\neq 0$”.
  2. [MAT] Línea [L323](../chap3.tex#L323) — Uso de $(z_k-z)$ introduce factor $(-1)^n$ en $P^{\#_n}$. **Corrección sugerida:** usar $\prod (z-z_k)$ de forma consistente.
  3. [MAT] Línea [L327](../chap3.tex#L327) — Falta el factor $(-1)^n$ en $P^{\#_n}$ si se mantiene $(z_k-z)$. **Corrección sugerida:** ajustar con $(-1)^n$ o cambiar la factorización.
  4. [MAT] Línea [L331](../chap3.tex#L331) — Mismo problema de signo al pasar a $\prod(1-\bar{z}_k z)$. **Corrección sugerida:** añadir $(-1)^n$ o reordenar factores.
  5. [MAT] Línea [L339](../chap3.tex#L339)-[L342](../chap3.tex#L342) — Inconsistencia repetida en la factorización de $P$ y $P^{\#_n}$. **Corrección sugerida:** unificar con $\prod (z-z_k)$.

## Bloque 6 — Álgebra del disco

- **Archivo:** [../chap3.tex](../chap3.tex)
- **Líneas:** [L392-L447](../chap3.tex#L392-L447)
- **Estado:** revisado — corregido
<!-- - **Comentarios:**
  1. [RED] Línea [L398](../chap3.tex#L398) — Texto visible del hipervínculo con guiones. **Corrección sugerida:** usar “álgebra del disco” como texto visible.
  2. [RED] Línea [L420](../chap3.tex#L420) — “i.e.” en texto en español. **Corrección sugerida:** “es decir”. -->

## Bloque 7 — Composición de productos finitos de Blaschke

- **Archivo:** [../chap3.tex](../chap3.tex)
- **Líneas:** [L448-L472](../chap3.tex#L448-L472)
- **Estado:** revisado — corregido
<!-- - **Comentarios:**
  1. [RED] Línea [L462](../chap3.tex#L462) — $w \in \mathbb{D}$ no se usa. **Corrección sugerida:** eliminar esa parte. -->

## Bloque 8 — Caracterización de $\mathscr{B}$ en $\mathscr{S}$

- **Archivo:** [../chap3.tex](../chap3.tex)
- **Líneas:** [L473-L635](../chap3.tex#L473-L635)
- **Estado:** revisado — con observaciones
- **Comentarios:**
  1. [MAT] Línea [L485](../chap3.tex#L485)-[L488](../chap3.tex#L488) — La $n$-valencia no garantiza que $0\in f(\mathbb{D})$ ni exactamente $n$ ceros. **Corrección sugerida:** asumir $0\in f(\mathbb{D})$ o reformular en términos de “a lo sumo $n$”.
  2. [TEX] Línea [L487](../chap3.tex#L487) — “in” en lugar de “\in”. **Corrección sugerida:** “$\forall z \in D(a_\ell, \varepsilon_\ell)$”.

## Comentarios generales

<!-- Lista numerada con comentarios generales sobre el capitulo -->
