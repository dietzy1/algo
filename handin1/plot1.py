import matplotlib.pyplot as plt
import numpy as np

# Data for N and time spent
n_values = [100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400]

# Time spent for A1, A2, A3, and A4 in seconds
time_spent_a1 = [
    0.000002, 0.000002, 0.000002, 0.000002, 0.000002, 0.000002,
    0.000003, 0.000002, 0.000003, 0.000004, 0.000003, 0.000004,
    0.000005, 0.000005
]

time_spent_a2 = [
    0.000025, 0.000095, 0.000206, 0.000312, 0.000484, 0.000697,
    0.000946, 0.001241, 0.001562, 0.001940, 0.002339, 0.002869,
    0.003292, 0.003739
]

time_spent_a3 = [
    0.003078, 0.025193, 0.080410, 0.184376, 0.357445, 0.621347,
    0.975038, 1.463639, 2.098991, 2.934203, 3.838246, 4.948421,
    6.304744, 7.884558
]

time_spent_a4 = [
    0.000010, 0.000034, 0.000114, 0.000221, 0.000245, 0.000331,
    0.000488, 0.000651, 0.000751, 0.000881, 0.000995, 0.001290,
    0.001481, 0.001572
]

# Create a 2x2 grid of subplots for each function with curved lines and regression lines
plt.figure(figsize=(12, 12))

# Plot for Time spent on A1 (Linear)
plt.subplot(2, 2, 1)
plt.plot(n_values, [time * 1000 for time in time_spent_a1], 'o-', label='Snippet 1(ms)')
plt.xlabel('N')
plt.title('Snippet 1')

# Fit the linear regression line using numpy.polyfit with a degree of 1
x = np.array(n_values)
y = np.array([time * 1000 for time in time_spent_a1])
coefficients = np.polyfit(x, y, 1)  # Fit a linear regression model
polynomial = np.poly1d(coefficients)
y_reg = polynomial(x)

# Add the regression line to the plot
plt.plot(x, y_reg, label=f'Linear Regression (y={coefficients[0]:.6f}x+{coefficients[1]:.6f})', linestyle='--', color='red')
plt.legend()

# Plot for Time spent on A2 (Quadratic)
plt.subplot(2, 2, 2)
plt.plot(n_values, [time * 1000 for time in time_spent_a2], 'o-', label='Snippet 2 (ms)')
plt.xlabel('N')
plt.title('Snippet 1')

# Fit the quadratic regression curve using numpy.polyfit with a degree of 2
x = np.array(n_values)
y = np.array([time * 1000 for time in time_spent_a2])
coefficients = np.polyfit(x, y, 2)  # Fit a quadratic regression model
polynomial = np.poly1d(coefficients)
y_reg = polynomial(x)

# Add the regression curve to the plot
plt.plot(x, y_reg, label=f'Quadratic Regression (y={coefficients[0]:.6f}x^2+{coefficients[1]:.6f}x+{coefficients[2]:.6f})', linestyle='--', color='red')
plt.legend()

# Plot for Time spent on A3 (Cubic)
plt.subplot(2, 2, 3)
plt.plot(n_values, [time * 1000 for time in time_spent_a3], 'o-', label='Snippet 3(ms)')
plt.xlabel('N')
plt.title('Snippet 1')

# Fit the cubic regression curve using numpy.polyfit with a degree of 3
x = np.array(n_values)
y = np.array([time * 1000 for time in time_spent_a3])
coefficients = np.polyfit(x, y, 3)  # Fit a cubic regression model
polynomial = np.poly1d(coefficients)
y_reg = polynomial(x)

# Add the regression curve to the plot
plt.plot(x, y_reg, label=f'Cubic Regression (y={coefficients[0]:.6f}x^3+{coefficients[1]:.6f}x^2+{coefficients[2]:.6f}x+{coefficients[3]:.6f})', linestyle='--', color='red')
plt.legend()

# Plot for Time spent on A4 (Cubic)
plt.subplot(2, 2, 4)
plt.plot(n_values, [time * 1000 for time in time_spent_a4], 'o-', label='Snippet 4 (ms)')
plt.xlabel('N')
plt.title('Snippet 1')

# Fit the cubic regression curve using numpy.polyfit with a degree of 3
x = np.array(n_values)
y = np.array([time * 1000 for time in time_spent_a4])
coefficients = np.polyfit(x, y, 3)  # Fit a cubic regression model
polynomial = np.poly1d(coefficients)
y_reg = polynomial(x)

# Add the regression curve to the plot
plt.plot(x, y_reg, label=f'Cubic Regression (y={coefficients[0]:.6f}x^3+{coefficients[1]:.6f}x^2+{coefficients[2]:.6f}x+{coefficients[3]:.6f})', linestyle='--', color='red')
plt.legend()




plt.tight_layout()
plt.show()
