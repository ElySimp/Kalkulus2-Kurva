import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import sympy as sp

def plot_3d_curve(user_input):
    x, y, z = sp.symbols('x y z')
    equation = sp.sympify(user_input)
    
    x_vals = np.linspace(-10, 10, 100)
    y_vals = np.linspace(-10, 10, 100)
    
    X, Y = np.meshgrid(x_vals, y_vals)
    f = sp.lambdify((x, y, z), equation, 'numpy')
    Z = f(X, Y, 0)
    
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    ax.plot_surface(X, Y, Z, cmap='viridis')
    
    ax.set_xlabel('X axis')
    ax.set_ylabel('Y axis')
    ax.set_zlabel('Z axis')
    
    plt.show()

# Contoh penggunaan
# user_input = "3*x**2 + y + 2*z"
user_input = "3*x**2 + y**2 + 2*z**2"
# user_input = input("Masukkan persamaan: ")
plot_3d_curve(user_input)