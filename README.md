# Integral-Approach-to-the-Geometry-of-Circles-Spheres-and-Pi
An analytical and empirical analysis of Pi computation, comparing a localized fractional binomial integration framework against the Chudnovsky algorithm via C and GMP.
## Mathematical Core

The project evaluates two distinct approaches to compute $\pi$ up to 1000 decimal places:

1. **Proposed Binomial Integration:** Derived from the circular boundary equation $y = \sqrt{r^2 - x^2}$ integrated from $0$ to $1/2$ to avoid slow convergence at the boundary edges. The fractional expansion yields a linear convergence rate of $\log_{10}(4) \approx 0.602$ digits per iteration, requiring $1700$ steps to satisfy the target precision.
2. **Chudnovsky Algorithm:** Rooted in the properties of modular functions and elliptic curves, yielding approximately $14.18$ correct decimal digits per step, requiring $72$ iterations.

## Hardware Configuration

All benchmarks were executed natively on the following system specification:
* **Architecture:** ARM64 (Apple Silicon)
* **Processor:** Apple M3
* **Memory:** 8 GB Unified Memory
* **Operating System:** macOS
* **Compiler:** Apple Clang / GCC with GMP 6.3.0 library integration

## Empirical Performance Results

The simulation tracks the exact processor execution time via `<time.h>` clock cycles to compute exactly 1000 decimal digits:

| Method | Target Precision | Required Iterations | Execution Time (ms) |
| :--- | :---: | :---: | :---: |
| Proposed Binomial Integration | 1000 digits | 1700 | 165.69 ms |
| Chudnovsky Framework Baseline | 1000 digits | 72 | 0.12 ms |

## Repository Structure

* `benchpi.c` — Complete source code containing both iterative loop implementations, memory allocation, and the benchmarking timer.
* `paper.pdf` — The full analytical research paper compiled in LaTeX detailing the geometric derivation and convergence mathematics.

## Compilation and Execution

To link the GMP library and run the benchmark on macOS, execute the following commands in the terminal:

```bash
gcc -I/opt/homebrew/include -L/opt/homebrew/lib benchpi.c -o benchpi -lgmp
./benchpi
```

