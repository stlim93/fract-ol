*This project has been created as partof the 42 curriculum by stelim.*

# Description
This project introduces low-level graphic by implementing fractals. Fractals implemented are Mandelbrot, Julia and Tricorn (or known as Mandelbar) set.

## Mandelbrot set
Mandelbrot set are sets of coordinate $(x,y)$ that satisfies 
$$z_{n} = z_{n-1}^2+c$$
where $z_{n}$ converges with initial value $z_{0} = 0$ and $c = x+iy$ is complex number. Note that $z_{n}$ can diverge depending on the values of $(x,y)$ hence a maximum iteration of $n=50$ is set.

## Julia set
Julia set is defined similar as Mandelbrot except that $c=x_{0}+y_{0}i$ remain fixed and $z_{n}$ is iterated up to a maximum iteration. The coordinates $(x,y)$ such that the $\lim_{n\rightarrow \infty}z_{n} \not\rightarrow\infty$ is called convergent and otherwise divergent.

## Tricorn / Mandelbar set
Mandelbrot set are sets of coordinate $(x,y)$ that satisfies 
$$z_{n} = \bar{z}_{n-1}^2+c$$
where $z_{n}$ converges with initial value $z_{0} = 0$ and $c = x+iy$ is complex number. Note that $z_{n}$ can diverge depending on the values of $(x,y)$ hence a maximum iteration of $n=50$ is set.


# Instructions
1. Git clone the repo
2. Download minilib to the root of the folder.
3. Download libft to the root of the folder.
4. Run `make`. It will make `libft/libft.a` and `minilib-linux/mlx.a`.
5. Enter the sample command below to run any of the fractal sets.  
```C
./fractol mandelbrot				// No arguments required
./fractol mandelbar					// No arguments required
./fractol tricorn					// No arguments required
./fractol julia "0.5125" "0.5215"	// Two floats
```
6. You may use the following operations to navigate the plot.

| Key / Mouse Events | Effect|
|---|---|
| Arrow keys | Move around the plot |
| C key | Reset the map |
| '-' key | Zoom out from the center of the plot|
| '+' key | Zoom out from the center of the plot|
| Mouse scroll wheel | Zoom in/out from the cursor|
| ESC Key or 'X' button | Close the window|

# Resources
## References 
1. [Guide to minilibx by Harm Smits](https://harm-smits.github.io/42docs/libs/minilibx.html) - Great introduction to minilibx and how thing works.

## AI Declaration
Claude AI was used to debug and understand errors from memory leaks.

