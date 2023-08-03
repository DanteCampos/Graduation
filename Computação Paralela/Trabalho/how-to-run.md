To generate the full set of graphs:
```bash
python3 generate_graphs.py
```

To run the sequential solution:
```bash
gcc prodCartArray.c -o prodCartC
./prodCartC
```

To run the parallel solution:
```bash
nvcc prodCart.cu -o prodCartCUDA
./prodCartCuda
```

If you wish to save the output graphs (on `CUDAresult` and `SEQresult` folders) uncomment the below section in both `prodCartArray.c` and `prodCart.cu` files:
```c
// Saving result as a file (consumes a LOT of time)
generate_result_file_name(result_file_name, dirIndex,
    vertices_string_G, edges_string_G, vertices_string_H, edges_string_H);
write_result_file(result_file_name, edge_array_P, edges_P);
```

The time results (in CPU cycles) are saved in `CUDAtime` and `SEQtime`.