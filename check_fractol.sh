./fractol m
valgrind ./fractol m

./fractol mandelbrot asd
valgrind ./fractol mandelbrot asd

valgrind ./fractol julia a b
valgrind ./fractol julia "a" "b"
valgrind ./fractol julia " a " " b "
valgrind ./fractol julia " a.c " " b.c "

./fractol
./fractol julia
./fractol julia abc xyz
valgrind ./fractol mandelbrot



# ./fractol mandelbrot
# ./fractol julia 0.3 0.5