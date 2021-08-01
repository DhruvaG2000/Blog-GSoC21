---
sort: 11
---

# Week10

## Logs from July 30 to Aug 06

- Wrote "[Running the sinetone example on the BBAI](https://dhruvag2000.github.io/Blog-GSoC21/Bela/example_run.html)" blog.
- Replaced std::map to std::vector approach in PruManager RProc + Mmap part.
- accumulated all the files necessary for the PRU code compilation in one place on the PruManager branch.
- tested the PruManager branch with all the new changes and verified that it works
- Got GPIO working on BBAI + BELA
- Almost got SPI working, small issue faced was that the MOSI and MISO seem to be swapped in the BBB vs BBAI. Have to make those changes in the overlay and also the pru code.
