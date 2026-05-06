*This project has been created as partof the 42 curriculum by stelim.*

# Description
This project introduces low-level graphic by implementing fractals. Fractals implemented are Mandelbrot and Julia set.

## Mandelbrot set
Mandelbrot set are sets of coordinate $(x,y)$ that satisfies 
$$z_{n} = z_{n-1}^2+c$$
where $z_{n}$ converges with initial value $z_{0} = 0$ and $c = x+iy$ is complex number. Note that $z_{n}$ can diverge depending on the values of $(x,y)$ hence a maximum iteration of $n=1000$ is set.

## Julia set
Julia set is defined similar as Mandelbrot except that $c=x_{0}+y_{0}i$ remain fixed and $z_{n}$ is iterated up to a maximum iteration. The coordinates $(x,y)$ such that the $\lim_{n\rightarrow \infty}z_{n} \not\rightarrow\infty$ is called convergent and otherwise divergent.

## Tricorn set



# Instructions
1. Git clone the


## Sample
./fractol mandelbrot
./fractol mandelbar
./fractol tricorn
./fractol julia "0.5125" "0.5215"


# Resources
## References 
1. [Guide to minilibx by Harm Smits](https://harm-smits.github.io/42docs/libs/minilibx.html) - Great introduction to minilibx and how thing works.

## AI Declaration
Claude AI was used to debug and understand errors from memory leaks.

