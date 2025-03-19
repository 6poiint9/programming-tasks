import matplotlib
matplotlib.use('Qt5Agg')  # Use Qt5 backend if TkAgg fails
import matplotlib.pyplot as plt

# Example data
x = [1, 2, 3, 4, 5]
y = [2, 3, 5, 7, 11]

# Create a simple line plot
plt.plot(x, y)

# Show the plot
plt.show()

