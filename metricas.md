# Esquema: Métricas en otros dominios de $\widehat{\mathbb{C}}$

## 1. Introducción
- Resumen del capítulo: la métrica de Poincaré $\wp$ en $\mathbb{D}$ es la única métrica riemanniana completa de curvatura constante $-1$ invariante por $\operatorname{Aut}(\mathbb{D})$.
- Pregunta natural: ¿podemos definir métricas análogas en otros dominios de $\widehat{\mathbb{C}}$?
- Teorema de uniformización: toda superficie de Riemann simplemente conexa es conformemente equivalente a una y solo una de:
  - $\widehat{\mathbb{C}}$ (esfera de Riemann),
  - $\mathbb{C}$ (plano complejo),
  - $\mathbb{D}$ (disco unidad).
- A cada una le corresponde una geometría modelo de curvatura constante:
  - Curvatura $+1$ → **métrica esférica** en $\widehat{\mathbb{C}}$.
  - Curvatura $0$ → **métrica euclídea** en $\mathbb{C}$.
  - Curvatura $-1$ → **métrica hiperbólica** en $\mathbb{D}$ (ya vista).

---

## 2. Métrica euclídea en $\mathbb{C}$
- Densidad métrica constante: $\mu_{\mathrm{euc}}(z) = 1$ (o $\mu_{\mathrm{euc}}(z)=2$, según normalización).
- Curvatura $\kappa_{\mu_{\mathrm{euc}}} = 0$ (cálculo directo).
- Geodésicas: rectas euclídeas.
- Invariante por el grupo de isometrías del plano: traslaciones, rotaciones, reflexiones.
- Relación con el capítulo: la métrica euclídea aparece como el "límite" de la métrica de Poincaré cuando $\mathbb{D}$ se aplana (curvatura $0$), y es la métrica inducida en $\mathbb{C}$ como recubrimiento universal de un toro (o del propio $\mathbb{C}$).
- **Precaución**: $\mathbb{C}$ con la métrica euclídea **no** es completo si restringimos a un subdominio propio (e.g. $\mathbb{D}$ no es completo con la métrica euclídea), tal y como se discute al inicio del capítulo. La completitud es una propiedad clave de la métrica de Poincaré.

---

## 3. Métrica hiperbólica en $\mathbb{H}$ (semiplano superior)

### 3.1 Definición mediante pullback
- $\mathbb{H}$ es conformemente equivalente a $\mathbb{D}$ mediante $\varphi(z) = \frac{z-i}{z+i}$, con inversa $\varphi^{-1}(w) = i\frac{1+w}{1-w}$.
- Densidad métrica inducida (pullback):
  \[
  \mu_{\mathbb{H}}(z) = (\varphi^*\mu)(z) = \mu(\varphi(z))\,|\varphi'(z)| = \frac{2}{\operatorname{Im}z}.
  \]
- **Verificación**: aplicar la definición de densidad inducida (Def. 2.3.2) usando que $\mu(z)=\frac{2}{1-|z|^2}$.

### 3.2 Propiedades
- Curvatura $\kappa_{\mu_{\mathbb{H}}} = -1$ (por el Lema 2.3.4, la curvatura es invariante por aplicaciones conformes).
- Geodésicas: semicircunferencias ortogonales a $\R$ y semirrectas verticales.
- $(\mathbb{H}, d_{\mu_{\mathbb{H}}})$ es isométrico a $(\mathbb{D}, \wp)$ mediante $\varphi$.
- El grupo de isometrías es $\operatorname{Aut}(\mathbb{H}) \mathbb{C}ong \operatorname{PSL}(2,\R)$ (transformaciones de Möbius con coeficientes reales y determinante $1$).

### 3.3 Relación con el capítulo
- Aplicar el Lema de Schwarz–Pick (o la versión de Ahlfors) a $f:\mathbb{D}\to\mathbb{H}$.
- Las funciones holomorfas $f:\mathbb{H}\to\mathbb{H}$ contraen la métrica hiperbólica.

---

## 4. Métrica esférica en $\widehat{\mathbb{C}}$

### 4.1 Definición
- Densidad métrica en $\mathbb{C}$:
  \[
  \mu_{\mathrm{esf}}(z) = \frac{2}{1+|z|^2},
  \]
  y $\mu_{\mathrm{esf}}(\infty)=0$ (la métrica se anula en el infinito).
- Origen: pullback de la métrica estándar de $S^2$ mediante la proyección estereográfica $\pi:\widehat{\mathbb{C}}\to S^2$:
  \[
  \pi(z) = \left(\frac{2\operatorname{Re}z}{1+|z|^2},\; \frac{2\operatorname{Im}z}{1+|z|^2},\; \frac{|z|^2-1}{1+|z|^2}\right),\quad \pi(\infty)=(0,0,1).
  \]
- Distancia esférica: $d_{\mathrm{esf}}(z,w) = \frac{2|z-w|}{\sqrt{1+|z|^2}\sqrt{1+|w|^2}}$ (para $z,w\in\mathbb{C}$), con la extensión adecuada para $\infty$.

### 4.2 Propiedades
- Curvatura $\kappa_{\mu_{\mathrm{esf}}} = +1$.
- $\widehat{\mathbb{C}}$ con la métrica esférica es completo (es isométrico a $S^2$).
- Geodésicas: circunferencias máximas en $S^2$, que corresponden a circunferencias o rectas en $\widehat{\mathbb{C}}$.
- Grupo de isometrías: $\operatorname{Aut}(\widehat{\mathbb{C}}) \mathbb{C}ong \operatorname{PSL}(2,\mathbb{C})$ (las transformaciones de Möbius que preservan la métrica esférica son las transformaciones de Möbius que son, de hecho, las isometrías de la esfera de Riemann).

### 4.3 Relación con el capítulo
- Aplicaciones holomorfas $f:\mathbb{D}\to\widehat{\mathbb{C}}$ ($f$ meromorfa acotada). La versión de Ahlfors del lema de Schwarz se aplica comparando con la curvatura $+1$ (en cuyo caso la dirección de la desigualdad se invierte o requiere una formulación distinta).
- Puede discutirse la **fórmula de Schwarz–Ahlfors–Pick** para este caso.

---

## 5. Métrica hiperbólica en un dominio simplemente conexo arbitrario $\Omega\subsetneq\mathbb{C}$

### 5.1 Construcción via el teorema de la aplicación de Riemann
- Por el teorema de Riemann, existe un biholomorfismo $f:\mathbb{D}\to\Omega$.
- La métrica hiperbólica en $\Omega$ se define mediante el pushforward:
  \[
  \mu_\Omega(w) = \frac{\mu(f^{-1}(w))}{|(f^{-1})'(w)|} = \frac{1}{|f'(f^{-1}(w))|}\mathbb{C}dot\frac{2}{1-|f^{-1}(w)|^2}.
  \]
- Esta métrica es independiente de la elección de $f$ (invariante por automorfismos de $\mathbb{D}$).

### 5.2 Propiedades
- $\kappa_{\mu_\Omega} = -1$.
- $(\Omega, d_{\mu_\Omega})$ es isométrico a $(\mathbb{D}, \wp)$.
- Geodésicas: imágenes de rectas hiperbólicas de $\mathbb{D}$ mediante $f$.
- Las funciones holomorfas entre dominios hiperbólicos contraen la métrica (generalización del lema de Schwarz–Pick).

### 5.3 Limitación
- Esta construcción solo funciona para dominios simplemente conexos. Para dominios con más de dos puntos en el complemento (dominios hiperbólicos en sentido de Poincaré), se usa el recubrimiento universal.

---

## 6. Cuadro resumen

| Dominio | Métrica | Densidad | Curvatura | Grupo de isometrías |
|---------|---------|----------|-----------|---------------------|
| $\widehat{\mathbb{C}}$ | esférica | $\frac{2}{1+|z|^2}$ | $+1$ | $\operatorname{PSL}(2,\mathbb{C})$ |
| $\mathbb{C}$ | euclídea | $1$ | $0$ | traslaciones + rotaciones |
| $\mathbb{D}$ | Poincaré | $\frac{2}{1-|z|^2}$ | $-1$ | $\operatorname{Aut}(\mathbb{D})$ |
| $\mathbb{H}$ | hiperbólica | $\frac{2}{\operatorname{Im}z}$ | $-1$ | $\operatorname{PSL}(2,\R)$ |
| $\Omega\subsetneq\mathbb{C}$ s.c. | hiperbólica | vía Riemann | $-1$ | $\operatorname{Aut}(\Omega)$ |

---

## 7. Preguntas conceptuales

1. **¿A cada conjunto de $\mathbb{C}$ le corresponde una métrica "natural"?**
   No. Solo los dominios cuyo complemento tiene al menos dos puntos (dominios hiperbólicos) admiten una métrica canónica
   (la métrica de Poincaré–Kobayashi). Los dominios simplemente conexos propios la heredan del disco mediante el teorema
   de Riemann. Para dominios más generales, la métrica de Kobayashi proporciona una construcción general (pero no siempre
   es riemanniana).

2. **¿Es $\mathbb{C}$ el único al que le corresponde la métrica euclídea?**
   Sí, en el sentido del teorema de uniformización: $\mathbb{C}$ es la única superficie de Riemann simplemente conexa que admite
   una métrica completa, conforme y de curvatura constante $0$ (salvo isometría). Equivalentemente, $\mathbb{C}$ con la métrica
   euclídea es el recubrimiento universal de todas las superficies de Riemann planas (toro complejo).

3. **Relación con el teorema de la aplicación de Riemann.**
   El teorema de Riemann reduce el estudio de todos los dominios simplemente conexos propios $\Omega\subsetneq\mathbb{C}$ al
   estudio de $\mathbb{D}$. En particular, la métrica hiperbólica de $\Omega$ se define mediante la identificación
   conforme con $\mathbb{D}$, y es canónica. Esto es una manifestación del principio de que "toda la geometría conforme
   de los dominios simplemente conexos es la geometría hiperbólica del disco".
