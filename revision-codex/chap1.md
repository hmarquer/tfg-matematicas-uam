## Bloque 0 — Introducción del capítulo

- **Archivo:** [../chap1.tex](../chap1.tex)
- **Líneas:** [L1-L16](../chap1.tex#L1-L16)
- **Estado:** revisado — corregido
<!-- - **Comentarios:** -->
  <!-- 1. [RED] Línea [L3](../chap1.tex#L3) — Redundancia en “$f$ es holomorfa” con el enlace embebido. **Corrección sugerida:** “$f$ es \exhyperref[defn:fn-holomorfa]{holomorfa}” o “$f$ es holomorfa” con el enlace en el texto.
  2. [TEX] Línea [L4](../chap1.tex#L4) — Uso de `\bar{\mathbb{D}}` para el cierre. **Corrección sugerida:** usar `\overline{\mathbb{D}}` para claridad tipográfica.
  3. [RED] Línea [L8](../chap1.tex#L8) — Redacción innecesariamente larga. **Corrección sugerida:** “Sea $f \in \mathscr{S}$ con $f(0)=0$. Entonces…”.
  4. [TEX] Línea [L11](../chap1.tex#L11) — Enlace sobre el apóstrofo de la derivada es frágil. **Corrección sugerida:** usar `$f'(0)$` y mover el enlace al texto o enlazar la expresión completa. -->

## Bloque 1 — Automorfismos del disco unidad

- **Archivo:** [../chap1.tex](../chap1.tex)
- **Líneas:** [L17-L38](../chap1.tex#L17-L38)
- **Estado:** revisado — corregido
<!-- - **Comentarios:** -->
  <!-- 1. [RED] Línea [L24](../chap1.tex#L24) — Uso de `\implies` en texto definicional. **Corrección sugerida:** “Definimos $\rho_\gamma(z)=\gamma z$. Entonces $\rho_\gamma \in \mathrm{Aut}(\mathbb{D})$.” -->

## Bloque 2 — Involuciones del disco unidad

- **Archivo:** [../chap1.tex](../chap1.tex)
- **Líneas:** [L39-L94](../chap1.tex#L39-L94)
- **Estado:** revisado — corregido
<!-- - **Comentarios:** -->
  <!-- 1. [MAT] Línea [L74](../chap1.tex#L74)-[L76](../chap1.tex#L76) — Se usa $w/|w|$ sin excluir $w=0$. **Corrección sugerida:** exigir $w \neq 0$ o añadir un caso aparte para $w=0$ con un diámetro fijo. -->

## Bloque 3 — Caracterización de $\mathrm{Aut} \left(\mathbb{D} \right)$

- **Archivo:** [../chap1.tex](../chap1.tex)
- **Líneas:** [L95-L130](../chap1.tex#L95-L130)
- **Estado:** revisado — corregido
<!-- - **Comentarios:**
  1. [RED] Línea [L100](../chap1.tex#L100) — Unicidad mejor expresada como par único. **Corrección sugerida:** “existe un único par $(\gamma,w) \in \mathbb{T}\times\mathbb{D}$ tal que…”.
  2. [RED] Línea [L110](../chap1.tex#L110) — Uso de “i.e.” en texto en español. **Corrección sugerida:** “es decir” o “esto es”.
  3. [MAT] Línea [L125](../chap1.tex#L125) — Argumento circular: se usa $f$ antes de definirlo. **Corrección sugerida:** definir $f=\rho_\gamma\circ\tau_{z_1}$ y luego elegir $\gamma$ para imponer $f(z_2)\in(0,1)$. -->

## Bloque 4 — Estructura algebraica de $\mathrm{Aut} \left(\mathbb{D} \right)$

- **Archivo:** [../chap1.tex](../chap1.tex)
- **Líneas:** [L131-L232](../chap1.tex#L131-L232)
- **Estado:** revisado — con observaciones
- **Comentarios:**
  <!-- 1. [NOT] Línea [L148](../chap1.tex#L148) — Variable mal especificada en la derivada. **Corrección sugerida:** “$\gamma = -f'(0)$”. -->
  2. [MAT] Línea [L218](../chap1.tex#L218)-[L230](../chap1.tex#L230) — Aparece $\bar{\gamma_2}$ en la definición de $\widetilde{\gamma}$ y en la simplificación, pero la composición previa involucra $\tau_{\bar{\gamma_1} a_2}$. **Corrección sugerida:** revisar la coherencia de índices y recalcular esas líneas (posible sustitución de $\bar{\gamma_2}$ por $\bar{\gamma_1}$).

## Bloque 5 — $\mathrm{Aut} \left(\mathbb{D} \right)$ como subgrupo de las aplicaciones de Möbius

- **Archivo:** [../chap1.tex](../chap1.tex)
- **Líneas:** [L233-L265](../chap1.tex#L233-L265)
- **Estado:** revisado — corregido
<!-- - **Comentarios:**
  1. [RED] Línea [L235](../chap1.tex#L235) — Redacción con cuantificadores en prosa. **Corrección sugerida:** “Para todo $\lambda \in \mathbb{C}\setminus\{0\}$, $A$ y $\lambda A$ definen la misma transformación de Möbius.”
  2. [MAT] Línea [L239](../chap1.tex#L239) — Falta aclarar la elección de la raíz. **Corrección sugerida:** “eligiendo $\mu$ con $\mu^2=\det A$, el representante $\mu^{-1}A$ tiene determinante $1$ (bien definido en el cociente).”
  3. [TEX] Línea [L243](../chap1.tex#L243) — Notación no estándar para Möbius en modo matemático. **Corrección sugerida:** usar `\operatorname{Mob}` o `\mathrm{Mob}`.
  4. [RED] Línea [L245](../chap1.tex#L245) — Mejora de estilo. **Corrección sugerida:** “existen $\gamma \in \mathbb{T}$ y $w \in \mathbb{D}$ tales que…”. -->

## Bloque 6 — Teorema de Schwarz-Pick

- **Archivo:** [../chap1.tex](../chap1.tex)
- **Líneas:** [L266-L333](../chap1.tex#L266-L333)
- **Estado:** revisado — corregido
<!-- - **Comentarios:**
  1. [RED] Línea [L282](../chap1.tex#L282)-[L285](../chap1.tex#L285) — Espaciado y sintaxis innecesarios tras “:”. **Corrección sugerida:** “$\exists z \neq w \in \mathbb{D}$: hay igualdad…” (sin espacio extra dentro del modo matemático).
  2. [TEX] Línea [L312](../chap1.tex#L312) — Comando `\we` no estándar. **Corrección sugerida:** usar `\wedge` o texto “y”.
  3. [MAT] Línea [L326](../chap1.tex#L326) — Enunciado del corolario queda trivial al usar $\tau_{\tau_w(w)}=\tau_0$. **Corrección sugerida:** enunciar directamente la forma estándar de Schwarz-Pick para $f=\tau_w$ o explicar por qué se reduce a $\tau_0$. -->

## Bloque 7 — Un problema extremal

- **Archivo:** [../chap1.tex](../chap1.tex)
- **Líneas:** [L334-L356](../chap1.tex#L334-L356)
- **Estado:** revisado — corregido
<!-- - **Comentarios:**
  1. [RED] Línea [L343](../chap1.tex#L343) — Inconsistencia de mayúsculas en el nombre del teorema. **Corrección sugerida:** “teorema de Schwarz-Pick”.
  2. [RED] Línea [L352](../chap1.tex#L352) — “segunda desigualdad” sin anclaje claro. **Corrección sugerida:** “la desigualdad del teorema de Schwarz-Pick” o “la desigualdad anterior”. -->

## Comentarios generales

<!-- Lista numerada con comentarios generales sobre el capitulo -->
