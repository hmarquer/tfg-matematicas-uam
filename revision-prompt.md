Analiza los contenidos de este trabajo de fin de grado de matemáticas. El proyecto LaTeX tiene un archivo principal desde el que se hace `\input` de los capítulos. **Solo debes revisar los archivos `chap1.tex`, `chap2.tex`, `chap3.tex` y `chap4.tex`** — ignora `abstract.tex`, `intro.tex` y cualquier otro archivo auxiliar.

**Objetivo final:** realizar una revisión sistemática bloque a bloque en busca de erratas, errores matemáticos, imprecisiones, faltas ortográficas, inconsistencias de notación y posibles mejoras en la presentación. Por ahora, **solo crea la estructura de archivos — no revises el contenido todavía.**

---

**Tarea: crea una carpeta llamada `revision/` con la siguiente estructura:**

**1. Un archivo `chapN.md` por cada capítulo** (`chap1.md`, `chap2.md`, `chap3.md`, `chap4.md`).

Cada archivo debe contener una lista de bloques en los que se divide el capítulo correspondiente. Usa este criterio de granularidad:
- Si una `\section` es corta (pocas subsecciones o contenido breve), trátala como **un único bloque**.
- Si una `\section` es extensa, divídela en **un bloque por `\subsection`**.

Para cada bloque, incluye una entrada con este formato exacto (los hipervínculos deben ser válidos desde la carpeta `revision/`):

```markdown
## Bloque N — <Título de la sección o subsección>

- **Líneas:** L_inicio–L_fin <!-- En formato de hipervínculo a las líneas del archivo .tex -->
- **Estado:** pendiente

**Checklist de revisión:**
- [ ] [ORT] Ortografía y tipografía
- [ ] [RED] Redacción y estilo
- [ ] [NOT] Notación matemática
- [ ] [MAT] Errores matemáticos
- [ ] [REF] Referencias y estructura
- [ ] [TEX] LaTeX y formato
- [ ] [MEJ] Mejoras de presentación

**Comentarios:**
<!-- Lista numerada con los problemas encontrados, por orden de aparición en el bloque,
     referenciando la línea exacta del archivo .tex. Formato:
     1. [CAT] Línea XX — Descripción del problema. **Corrección sugerida:** corrección concreta. -->
```

La checklist indica qué categorías han sido revisadas en ese bloque (marcadas con `[x]`) y cuáles están pendientes (con `[ ]`). Se marca una categoría aunque no haya encontrado ningún problema en ella — lo importante es que fue inspeccionada.

**2. Un archivo `revision.md`** que actúe como índice y panel de control de toda la revisión, con este formato:

```markdown
# Revisión del TFG

## Capítulo N — <Título>
- Archivo fuente: ../chapN.tex <!-- Con hipervínculo al archivo .tex -->
- Archivo de revisión: chapN.md <!-- Con hipervínculo al archivo .md -->
- Bloques totales: N
- Bloques revisados: 0 / N
- Estado general: pendiente

**Checklist global del capítulo:**
- [ ] Bloque 1 — <Título>
- [ ] Bloque 2 — <Título>
- [ ] Bloque 3 — <Título>
...
```

Cada entrada de la checklist global se marca con `[x]` cuando ese bloque ha sido completamente revisado (todas las categorías inspeccionadas y comentarios anotados). El campo `Bloques revisados` se actualiza en consecuencia.

---

**Instrucciones adicionales:**
- Numera los bloques de forma continua dentro de cada capítulo (Bloque 1, Bloque 2, …).
- Las líneas indicadas deben corresponder al contenido real del `.tex`, incluyendo el comando de apertura de la sección/subsección y hasta la línea anterior al siguiente bloque.
- Si un capítulo tiene preámbulo antes de la primera `\section` (texto introductorio, definiciones iniciales, etc.), inclúyelo como **Bloque 0 — Introducción del capítulo**.
- No omitas ninguna parte del capítulo: cada línea del `.tex` debe quedar cubierta por algún bloque.

Una vez confirmes que la estructura está bien, comenzaremos a revisar bloque por bloque.

---

**Sección final obligatoria en cada `chapN.md`:**

Al final de cada archivo `chapN.md`, añade una sección titulada **"Comentarios generales"** con este formato exacto:

```markdown
## Comentarios generales
<!-- Lista numerada con observaciones transversales del capítulo: coherencia global,
     flujo narrativo, uso consistente de notación a lo largo del capítulo, etc. -->
```
