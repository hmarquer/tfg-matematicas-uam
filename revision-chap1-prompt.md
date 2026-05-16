Tienes acceso a `chap3.tex` y al archivo `revision/chap3.md` que contiene la lista de bloques del capítulo 3. El TFG está escrito en español.

**Tarea:** lanza dos tipos de agentes en paralelo:

---

### Agente tipo A — Revisión por bloques

Para cada bloque definido en `chap3.md`, lanza un agente independiente que lea las líneas exactas indicadas en el campo `Líneas` del bloque correspondiente y anote todos los problemas encontrados.

**Qué debe buscar cada agente — categorías de revisión:**

**[ORT] Ortografía y tipografía**
- Faltas de ortografía o acentuación.
- Puntuación incorrecta o ausente (p.ej. falta de punto al final de una ecuación en línea, coma antes de "entonces", etc.).
- Uso incorrecto de comillas, guiones o apóstrofes.
- Espaciado incorrecto entre palabras o tras puntuación.

**[RED] Redacción y estilo**
- Frases ambiguas, confusas o mal construidas gramaticalmente.
- Uso inconsistente del tiempo verbal o la persona narrativa (p.ej. mezclar "sea" con "es", o "consideramos" con "se considera").
- Redundancias o formulaciones que se puedan expresar con más claridad o precisión.
- Conectores lógicos mal usados (p.ej. "por tanto" donde corresponde "sin embargo").

**[NOT] Notación matemática**
- Símbolos definidos de una forma y usados de otra.
- Notación introducida sin definir previamente.
- Inconsistencias en el uso de mayúsculas/minúsculas para conjuntos, variables, funciones, etc.
- Abuso de notación no advertido o no justificado.
- Mezcla de notaciones distintas para el mismo objeto (p.ej. `f(x)` vs. `f_x` vs. `fx`).

**[MAT] Errores matemáticos**
- Afirmaciones incorrectas, incompletas o que requieren hipótesis adicionales no mencionadas.
- Demostraciones con pasos injustificados, saltos lógicos o argumentos circulares.
- Resultados citados sin referencia o atribuidos incorrectamente.
- Condiciones de un teorema, definición o proposición que no concuerdan con su enunciado o su uso posterior.
- Errores en cálculos, índices, signos o límites de sumatorios/integrales.

**[REF] Referencias y estructura**
- Referencias a ecuaciones, teoremas, figuras o secciones que no existen o están mal numeradas.
- Etiquetas LaTeX (`\label`, `\ref`, `\eqref`) rotas o inconsistentes.
- Figuras o tablas mencionadas en el texto pero no definidas cerca, o viceversa.

**[TEX] LaTeX y formato**
- Comandos LaTeX mal usados o que producen un resultado visualmente incorrecto (p.ej. usar `$...$` donde corresponde `\[...\]`, o `\leq` donde se quería `\geq`).
- Entornos mal cerrados o anidados incorrectamente.
- Uso inconsistente de entornos para definiciones, teoremas, lemas, etc.
- Espaciado forzado con `\\` o `\vspace` donde debería usarse estructura semántica.

**[MEJ] Mejoras de presentación**
- Contenido que, sin ser incorrecto, se podría reorganizar, desglosar o ilustrar mejor.
- Ejemplos que ayudarían a asentar un concepto abstracto.
- Transiciones entre secciones o resultados que podrían ser más fluidas.
- Definiciones o enunciados que ganarían claridad con una reformulación menor.

**Formato de salida para cada agente tipo A:**

Actualiza el campo `Comentarios` del bloque correspondiente en `revision/chap3.md` con una lista numerada. Cada entrada debe seguir este formato:

```markdown
**Comentarios:**
1. [CAT] Línea XX — <Descripción del problema>. **Corrección sugerida:** <corrección concreta>.
2. [CAT] Línea XX — <Descripción del problema>. **Corrección sugerida:** <corrección concreta>.
```

Si un bloque no presenta ningún problema en una categoría, márcala igualmente con `[x]` en la checklist — lo importante es que fue inspeccionada. Si el bloque no presenta ningún problema en ninguna categoría, escribe:

```markdown
**Comentarios:**
- Sin observaciones.
```

Actualiza el campo `Estado` del bloque:
- `revisado — sin errores` si no hay observaciones.
- `revisado — con observaciones` si hay al menos una entrada.

---

### Agente tipo B — Revisión global del capítulo

Lanza un único agente que lea `chap3.tex` al completo y realice una revisión exhaustiva del contenido a gran escala, con independencia de los bloques. Este agente debe evaluar:

**Contenido y cobertura**
- Resultados relevantes para el tema del capítulo que no se incluyen y deberían mencionarse o demostrarse.
- Conceptos que se introducen sin suficiente motivación o contexto previo.
- Cuestiones que no se exploran con el detalle necesario dado el nivel y objetivo del trabajo.
- Ejemplos o contraejemplos adicionales que ayudarían a ilustrar o matizar los resultados.

**Estructura y organización**
- Reordenaciones del contenido que mejorarían el flujo lógico o pedagógico del capítulo.
- Secciones o bloques que deberían fusionarse, dividirse o reubicarse.
- Resultados que aparecen antes de haberse establecido las herramientas necesarias para comprenderlos.
- Ausencia de resúmenes, recapitulaciones o transiciones que conecten las partes del capítulo.

**Claridad y rigor**
- Argumentos o demostraciones que, siendo correctos, resultan difíciles de seguir y se beneficiarían de una explicación adicional.
- Definiciones o enunciados que admiten una formulación más clara o estándar.
- Hipótesis o condiciones que se asumen implícitamente a lo largo del capítulo sin haberlas declarado explícitamente.

**Estilo y coherencia global**
- Inconsistencias de tono o registro a lo largo del capítulo (p.ej. mezcla de estilo formal e informal).
- Variaciones en el nivel de detalle de las demostraciones sin justificación aparente (algunas muy detalladas, otras con saltos grandes).
- Uso inconsistente de la voz narrativa o de convenciones tipográficas a lo largo del capítulo.

**Formato de salida del agente tipo B:**

Anota los resultados en la sección `## Comentarios generales` al final de `revision/chap3.md`, con una lista numerada organizada por las subcategorías anteriores:

```markdown
## Comentarios generales

**Contenido y cobertura**
1. <Observación>. **Sugerencia:** <sugerencia concreta>.

**Estructura y organización**
1. <Observación>. **Sugerencia:** <sugerencia concreta>.

**Claridad y rigor**
1. <Observación>. **Sugerencia:** <sugerencia concreta>.

**Estilo y coherencia global**
1. <Observación>. **Sugerencia:** <sugerencia concreta>.
```

Si no hay observaciones en una subcategoría, escríbelo explícitamente: `- Sin observaciones.`

---

**Instrucciones finales (ambos tipos de agentes):**
- **No modifiques ningún archivo `.tex`.** Solo actualiza `revision/chap3.md`.
- Una vez completada la revisión, actualiza el campo `Bloques revisados` y marca las entradas correspondientes en la checklist global de `revision/revision.md`.