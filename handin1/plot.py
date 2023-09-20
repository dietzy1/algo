import matplotlib.pyplot as plt
import numpy as np

# Data for N and time spent
n_values = [100, 200, 300, 400, 500, 600, 700, 800, 900, 1000]

# Time spent for A1, A2, A3, and A4 in seconds
time_spent_a1 = [0.000002, 0.000002, 0.000001, 0.000002, 0.000002, 0.000002, 0.000003, 0.000002, 0.000003, 0.000002]
time_spent_a2 = [0.000025, 0.000098, 0.000210, 0.000345, 0.000498, 0.000700, 0.000943, 0.001223, 0.001391, 0.001636]
time_spent_a3 = [0.002299, 0.021638, 0.071905, 0.176138, 0.348788, 0.610352, 0.977092, 1.458027, 2.078741, 2.869889]
time_spent_a4 = [0.000010, 0.000036, 0.000079, 0.000134, 0.000212, 0.000298, 0.000408, 0.000555, 0.000728, 0.000872]

# Create a 2x2 grid of subplots for each function with curved lines and regression lines
plt.figure(figsize=(12, 12))

# Plot for Time spent on A1 (Linear)
plt.subplot(2, 2, 1)
plt.plot(n_values, [time * 1000 for time in time_spent_a1], 'o-', label='Time spent on A1 (ms)')
plt.xlabel('N')
plt.title('Time spent on A1 vs. N')

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
plt.plot(n_values, [time * 1000 for time in time_spent_a2], 'o-', label='Time spent on A2 (ms)')
plt.xlabel('N')
plt.title('Time spent on A2 vs. N')

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
plt.plot(n_values, [time * 1000 for time in time_spent_a3], 'o-', label='Time spent on A3 (ms)')
plt.xlabel('N')
plt.title('Time spent on A3 vs. N')

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
plt.plot(n_values, [time * 1000 for time in time_spent_a4], 'o-', label='Time spent on A4 (ms)')
plt.xlabel('N')
plt.title('Time spent on A4 vs. N')

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
