Sí. Esa es exactamente la dirección natural, y es muy potente.

La idea clave es esta: si $\Omega\subsetneq\mathbb C$ es simplemente conexo y eliges una aplicación de Riemann
$$
\phi:\mathbb D\to\Omega,\qquad \psi:=\phi^{-1},
$$
entonces toda la teoría del disco se transporta por conjugación.  
En términos técnicos, el operador
$$
\mathcal T_\phi(f):=\psi\circ f\circ\phi
$$
da una biyección entre aplicaciones holomorfas $\Omega\to\Omega$ y aplicaciones holomorfas $\mathbb D\to\mathbb D$.

---

**1. Automorfismos de $\Omega$ via automorfismos del disco**

Rigurosamente:
$$
\operatorname{Aut}(\Omega)=\phi\circ \operatorname{Aut}(\mathbb D)\circ \psi.
$$
Equivalente: $f\in\operatorname{Aut}(\Omega)$ si y solo si $\psi\circ f\circ\phi\in\operatorname{Aut}(\mathbb D)$.

Además, esto es un isomorfismo de grupos:
$$
\gamma\mapsto \phi\circ\gamma\circ\psi.
$$

Conexión métrica (muy alineada con tu capítulo): define la métrica de Poincaré de $\Omega$ por pullback
$$
\mu_\Omega(w)=\frac{2\,|\psi'(w)|}{1-|\psi(w)|^2},\qquad
\rho_\Omega(z,w):=\rho_{\mathbb D}(\psi(z),\psi(w)).
$$
Entonces:
1. Toda $f:\Omega\to\Omega$ holomorfa es contractiva para $\rho_\Omega$.
2. $f$ es automorfismo si y solo si es isometría de $\rho_\Omega$.
3. Equivalentemente, $f$ es automorfismo si y solo si
$$
(f^*\mu_\Omega)(z)=\mu_\Omega(z)\ \ \forall z.
$$
Esto es la versión intrínseca de Schwarz-Pick/Ahlfors-Schwarz en $\Omega$.

---

**2. “Productos de Blaschke en $\Omega$”: sí, pero con una precisión**

Aquí hay una sutileza importante.

En $\mathbb D$ un producto de Blaschke es un producto en $\mathbb C$:
$$
B(\zeta)=\eta\prod_{k=1}^n \tau_{a_k}(\zeta),\qquad a_k\in\mathbb D,\ |\eta|=1.
$$
En $\Omega$ no hay una operación “producto” canónica entre puntos de $\Omega$.  
Así que el objeto correcto se define por coordenadas de Riemann:

1. Tipo $\Omega\to\mathbb D$:
$$
B_\Omega(z):=\eta\prod_{k=1}^n \tau_{\psi(a_k)}(\psi(z)).
$$
Esto sí tiene “ceros” en $a_k\in\Omega$.

2. Tipo $\Omega\to\Omega$ (auténtico análogo de autoaplicación):
$$
F(z):=\phi\big(B(\psi(z))\big)=\phi\circ B\circ \psi.
$$

Estos son exactamente los conjugados de Blaschke finitos del disco.

Resultado estructural fuerte:
1. $F:\Omega\to\Omega$ es holomorfa propia de grado finito si y solo si
$$
F=\phi\circ B\circ\psi
$$
con $B$ un Blaschke finito.
2. El caso grado $1$ recupera exactamente los automorfismos de $\Omega$.

---

**3. ¿Depende de la aplicación de Riemann elegida?**

Solo cambia por conjugación interna, así que la teoría es intrínseca.

Si $\phi_1=\phi\circ\gamma_0$ con $\gamma_0\in\operatorname{Aut}(\mathbb D)$, entonces
$$
\phi_1\circ B\circ \phi_1^{-1}
=
\phi\circ (\gamma_0\circ B\circ \gamma_0^{-1})\circ \phi^{-1}.
$$
No cambias la clase de objetos; solo su representante en coordenadas.

---

**4. ¿Análogos de aproximación del último capítulo?**

Sí, en gran medida sí, y este es probablemente el salto más natural de tu trabajo.

Si en $\mathbb D$ tienes un resultado del tipo:
$$
g_n\to g \text{ en cierta topología } \tau,\quad g_n \text{ Blaschke finitos},
$$
entonces para $f=\phi\circ g\circ\psi$ defines
$$
f_n:=\phi\circ g_n\circ\psi,
$$
y obtienes la versión en $\Omega$ con la topología transportada.

En particular, para convergencia uniforme en compactos:
$$
g_n\to g \text{ en } \mathbb D
\iff
f_n\to f \text{ en } \Omega.
$$

Esto da un principio general:  
todo teorema del disco que sea invariante por conjugación biholomorfa se traduce automáticamente a $\Omega$.

---

**5. Qué sí y qué no se transporta “gratis”**

Sí se transporta directamente:
1. Schwarz-Pick y caracterización de igualdad.
	Referencias internas: \excref[teo:schwarz-pick]{teo-schwarz-pick} (incluyendo \ref{teo:schwarz-pick:i}--\ref{teo:schwarz-pick:v}) y versión por curvatura \excref[lem:alhfors-schwarz]{lem-alhfors-schwarz}.
2. Métrica de Poincaré y geodésicas vía coordenadas.
	Referencias internas: \excref[prop:metrica-poincare]{prop-metrica-poincare}, \excref[defn:longitud-hiperbolica]{defn-longitud-hiperbolica}, \excref[lem:invariancia-conforme-longitud-hiperbolica]{lem-invariancia-conforme-longitud-hiperbolica}, \excref[teo:camino-minimo-poincare]{teo-camino-minimo-poincare} y \excref[teo:completitud-metrica-poincare]{teo-completitud-metrica-poincare}.
3. Automorfismos y autoaplicaciones propias de grado finito.
	Referencias internas: para automorfismos del disco, \excref[defn:automorfismo-disco-unidad]{defn-automorfismo-disco-unidad}, \excref[teo:formula-aut-disco-unidad]{teo-formula-aut-disco-unidad}, \excref[teo:aut-disco-unidad-parametros]{teo-aut-disco-unidad-parametros}, \excref[teo:aut-disco-unidad-composicion]{teo-aut-disco-unidad-composicion}, \excref[prop:aut-disco-unidad-inversa]{prop-aut-disco-unidad-inversa}; para Blaschke finitos y estructura propia de grado finito, \excref[defn:producto-finito-blaschke]{defn-producto-finito-blaschke}, \excref[teo:carac-prod-finito-blaschke]{teo-carac-prod-finito-blaschke}, \excref[teo:n-valencia-prod-finito-blaschke-disco-unidad]{teo-n-valencia-prod-finito-blaschke-disco-unidad}, \excref[teo:composicion-prod-finito-blaschke]{teo-composicion-prod-finito-blaschke}.
4. Aproximación en compactos por conjugados de Blaschke.
	Referencias internas: \excref[lem:aprox-clase-schur-prod-finito-blaschke-orden-cero]{lem-aprox-clase-schur-prod-finito-blaschke-orden-cero}, \excref[teo:caratheodory-aproximacion-schur-prod-finito-blaschke-compactos]{teo-caratheodory-aproximacion-schur-prod-finito-blaschke-compactos}, \excref[teo:fisher-aproximacion-algebra-disco-conv-prod-finito-blaschke]{teo-fisher-aproximacion-algebra-disco-conv-prod-finito-blaschke}, \excref[teo:aproximacion-prod-finito-blaschke-ceros-simples]{teo-aproximacion-prod-finito-blaschke-ceros-simples}.

Requiere hipótesis extra (frontera regular, etc.):
1. Resultados con límites en frontera punto a punto.
	Referencias internas relacionadas con comportamiento en borde: \excref[teo:fatou-carac-prod-finito-blaschke-algebra-disco]{teo-fatou-carac-prod-finito-blaschke-algebra-disco}, \excref[cor:carac-prod-finito-blaschke-algebra-disco]{cor-carac-prod-finito-blaschke-algebra-disco}, \excref[cor:carac-cociente-prod-finito-blaschke-algebra-disco-meromorfa]{cor-carac-cociente-prod-finito-blaschke-algebra-disco-meromorfa}, \excref[teo:helson-sarason-aproximacion-fn-unimodular-continua-cociente-prod-finito-blaschke]{teo-helson-sarason-aproximacion-fn-unimodular-continua-cociente-prod-finito-blaschke}.
2. Formulaciones en normas de borde (Hardy/Smirnov en frontera geométrica concreta de $\Omega$).
	Referencias internas: \excref[obs:hinfty-subespacio-vectorial-holomorfas]{obs-hinfty-subespacio-vectorial-holomorfas}, \excref[prop:hinfty-esp-normado]{prop-hinfty-esp-normado}, \excref[obs:hinfty-bola-unidad]{obs-hinfty-bola-unidad}, y en el apéndice \excref[prop:fn-holomorfa-esencialmente-acotada-imp-acotada]{prop-fn-holomorfa-esencialmente-acotada-imp-acotada}.
3. Cualquier teorema que use fuertemente estructura lineal en el codominio (sumas/medias en $\mathbb C$), que puede no tener versión intrínseca inmediata en $\Omega$.
	Referencias internas donde esta estructura sí se usa en $\mathbb D$: \excref[defn:combinacion-convexa]{defn-combinacion-convexa}, \excref[prop:envolvente-convexa-combinacion-convexa]{prop-envolvente-convexa-combinacion-convexa}, \excref[lem:prod-combinacion-convexa-prod-finito-blaschke]{lem-prod-combinacion-convexa-prod-finito-blaschke}, \excref[lem:dilatacion-prod-finito-blaschke]{lem-dilatacion-prod-finito-blaschke}, \excref[teo:stone-weierstrass-toro]{teo-stone-weierstrass-toro}.

---

**6. Intuición geométrica final**

La aplicación de Riemann es una “carta global” que rectifica $\Omega$ al disco.  
En esa carta:
1. Los automorfismos de $\Omega$ son exactamente los Möbius del disco “vistos en coordenadas curvadas”.
2. Los Blaschke en $\Omega$ son los Blaschke clásicos escritos en la variable $\psi(z)$.
3. Los teoremas de aproximación no son nuevos fenómenos: son el mismo fenómeno en otra geometría conforme.

Dicho de forma corta: para dominios simplemente conexos propios, tu teoría del disco ya contiene, casi por completo, la teoría correspondiente en $\Omega$. El trabajo matemático está en escribir bien el diccionario y en controlar qué resultados son intrínsecos (conformes) y cuáles dependen de la frontera concreta.