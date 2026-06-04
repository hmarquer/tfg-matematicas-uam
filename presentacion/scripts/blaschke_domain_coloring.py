#!/usr/bin/env python3
"""Generate a domain-coloring image for a finite Blaschke product."""

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.colors import hsv_to_rgb

def blaschke(z, zeros):
    """Finite Blaschke product with zeros inside unit disk."""
    f = np.ones_like(z, dtype=np.complex128)
    for zk in zeros:
        zk = complex(zk)
        f *= (z - zk) / (1 - np.conjugate(zk) * z)
    return f

def polar_checkerboard(w, r_step=0.25, n_ang=10, strength=0.2):
    """Return a subtle polar checkerboard multiplier in [1-strength, 1+strength]."""
    r = np.abs(w)
    theta = np.angle(w)

    ang = (theta + np.pi) / (2 * np.pi)
    # ang_idx = np.floor(ang * n_ang)
    # r_idx = np.floor(r / r_step)
    r_idx = (np.log(r / r_step) / np.log(2)) % 1
    ang_idx = (ang * n_ang) % 1

    # checker = (r_idx + ang_idx) % 2
    checker = r_idx * ang_idx
    return 1.0 - strength + 2.0 * strength * checker

def domain_coloring(z, fz, use_mod_value=False, use_checkerboard=True):
    """Return RGB image for domain coloring of f(z)."""
    arg = np.angle(fz)
    mod = np.abs(fz)

    # Hue by argument in [0, 1)
    hue = (arg + np.pi) / (2 * np.pi)

    # Optional value by modulus (log-compressed for dynamic range)
    if use_mod_value:
        # Use log1p to keep near-zero values visible.
        value = 1.0 - 1.0 / (1.0 + np.log1p(mod))
    else:
        value = np.ones_like(mod)

    # Slight saturation boost; keep in [0, 1]
    sat = np.clip(0.85 + 0.15 * np.tanh(mod), 0.0, 1.0)

    hsv = np.stack([hue, sat, value], axis=-1)
    rgb = hsv_to_rgb(hsv)

    if use_checkerboard:
        checker = polar_checkerboard(fz)
        rgb = np.clip(rgb * checker[..., None], 0.0, 1.0)

    return rgb

def main():
    # User-editable zeros (must satisfy |zk| < 1)
    zeros = [
        0.2 + 0.4j,
        -0.35 + 0.25j,
        -0.35 + 0.25j,
        0.55 - 0.2j,
    ]

    # Image domain
    n = 900
    xlim = (-2.3, 2.3)
    ylim = (-2.3, 2.3)

    x = np.linspace(xlim[0], xlim[1], n)
    y = np.linspace(ylim[0], ylim[1], n)
    X, Y = np.meshgrid(x, y)
    Z = X + 1j * Y

    F = blaschke(Z, zeros)
    # Toggle optional effects
    use_mod_value = False
    use_checkerboard = True

    rgb = domain_coloring(Z, F, use_mod_value=use_mod_value, use_checkerboard=use_checkerboard)

    fig, ax = plt.subplots(figsize=(6, 6), dpi=200)
    ax.imshow(rgb, extent=(*xlim, *ylim), origin="lower")

    # Unit circle and zeros overlay
    theta = np.linspace(0.0, 2 * np.pi, 600)
    ax.plot(np.cos(theta), np.sin(theta), color="black", lw=4.)
    ax.plot(np.cos(theta), np.sin(theta), color="white", lw=3.)
    ax.scatter([z.real for z in zeros], [z.imag for z in zeros],
               s=40, c="white", marker="o", edgecolors="black", linewidths=0.6)

    ax.set_aspect("equal")
    ax.set_xlim(xlim)
    ax.set_ylim(ylim)
    ax.axis("off")

    fig.tight_layout(pad=0)
    fig.savefig("blaschke_domain_coloring.png", bbox_inches="tight", pad_inches=0)
    fig.savefig("blaschke_domain_coloring.pdf", bbox_inches="tight", pad_inches=0)

if __name__ == "__main__":
    main()
