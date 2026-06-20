# 🧮 Software Ray Tracer

> A custom CPU-based ray tracer built from scratch in C++, focused on physically-based light transport, explicit rendering mathematics, and foundational camera + geometry systems.

---

## ⚡ What This Project Is

This is a **low-level software rendering system** that implements core ray tracing fundamentals from first principles, without relying on GPU APIs or rendering engines.

It focuses on understanding how images are formed mathematically through:

- Ray–scene intersection
- Camera projection models
- Geometric reasoning in 3D space
- Light transport and sampling concepts
- Recursive ray evaluation

The project is being developed as a structured progression through core ray tracing literature and implementations (including Kevin Beason-style / smallpt-inspired approaches).

---

## 🧠 Core Rendering Systems

### 📷 Camera System (Pinhole Model)

- Fully implemented pinhole camera projection model
- Rays generated per pixel through normalized screen space
- Explicit mapping from image plane to world space rays
- Field-of-view controlled projection geometry
- Deterministic ray generation per pixel sample

---

### 🧭 Ray Generation Pipeline

- Primary ray construction per pixel
- Normalized device coordinate sampling
- Screen-space to world-space ray transformation
- Jitter-ready architecture for future anti-aliasing (SSAA path)

---

### 🧱 Geometry & Scene Representation

- Explicit mathematical scene representation
- Sphere-based primitive intersection system (initial stage)
- Extensible structure for future triangle mesh support
- Clean separation between:
  - Scene data
  - Intersection logic
  - Ray evaluation pipeline

---

### 🔍 Ray–Object Intersection System

- Analytical intersection tests (sphere-based)
- Deterministic hit/miss evaluation
- Distance-based nearest-hit resolution
- Structured hit record storage for shading pipeline

---

### 🧠 Numerical / Sampling Design

- Per-pixel deterministic sampling structure
- Clean separation of sampling and evaluation logic
- Designed to support future Monte Carlo integration
- Ready for stochastic sampling upgrades (AA / GI)

---

## 🧮 Rendering Pipeline (Mental Model)

> The renderer evaluates each pixel by casting rays from a virtual camera into a mathematical scene and computing intersections deterministically.

### Frame Execution Flow

- Generate camera rays per pixel
- Normalize ray direction through pinhole projection
- Test ray–scene intersections
- Compute closest hit point
- Evaluate surface response (normal / material logic)
- Write final color to framebuffer

---

## ⚙️ Performance Design Philosophy

- Pure CPU-based deterministic computation
- No hidden engine abstractions
- Explicit math-driven rendering pipeline
- Minimal memory overhead per pixel sample
- Focus on clarity of geometric computation over optimization (for now)

> The goal is correctness and understanding of light transport fundamentals before acceleration structures or GPU optimization.

---

## 🧱 Tech Stack

- C++ (ISO C++17)
- Standard library only (no graphics API dependency)
- Manual memory + data structures
- Optional image output via framebuffer dump

---

## 📐 Key Concepts Demonstrated

- Ray–geometry intersection mathematics
- Pinhole camera projection model
- 3D vector math and normalization
- Deterministic per-pixel evaluation
- Foundation of physically-based rendering pipelines
- Early-stage ray tracing architecture design

---

## 🧭 Current Work

- Expanding camera model correctness (FOV + aspect ratio refinement)
- Improving ray–scene abstraction layer
- Preparing for multi-sample anti-aliasing (SSAA)
- Transition toward recursive ray tracing (bounce system)

---

## 🚀 Future Work

- Diffuse + specular BRDF implementation
- Recursive path tracing (global illumination)
- Acceleration structures (BVH / KD-tree)
- Multi-sample anti-aliasing (SSAA / Monte Carlo sampling)
- Triangle mesh intersection support
- Importance sampling for light transport
- GPU acceleration exploration (CUDA / DX12 compute comparison)

---

## 📚 Resources & Inspiration

This project is being developed with direct reference to established ray tracing literature and educational material, with a focus on building a correct foundation from first principles.

- **Kevin Suffern — *Ray Tracing from the Ground Up***
  Core reference for the mathematical and architectural foundations of ray tracing, including camera models, geometric primitives, and rendering pipeline structure.

- **Scratchapixel (Online Reference)**
  Supporting reference for geometric optics, ray–object intersection mathematics, and camera projection models.

- Additional understanding derived from iterative implementation, debugging visual output, and progressive refinement of rendering correctness.

---

## 🧠 Why This Project Exists

This project is built to deeply understand how images are formed from first principles by implementing:

- Camera models
- Geometric ray construction
- Analytical intersection mathematics
- The foundations of physically-based rendering

It complements real-time engine development by focusing on **offline correctness, mathematical clarity, and light transport fundamentals**.

---