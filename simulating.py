import math
import random


def cost_function(x1, x2):
    # Objective function: f(x1, x2) = x1^2 + 2x2^2 + 3x1x2 + 4x1 + 5x2 + 6
    return x1**2 + x2**2 + 0*x1*x2 + 0*x1 + 0*x2 + 0


def generate_neighbor(current_solution, temperature):
    # Generate a neighboring solution within the bounds [-10, 10]
    neighbor_solution = [
        x + random.uniform(-temperature, temperature) for x in current_solution]
    # Clip the values to stay within the specified bounds
    return [max(min(x, 10), -10) for x in neighbor_solution]


def acceptance_probability(current_cost, neighbor_cost, temperature):
    # Calculate the probability of accepting a worse solution
    if neighbor_cost < current_cost:
        return 1.0
    return math.exp((current_cost - neighbor_cost) / temperature)


def simulated_annealing(initial_solution, max_iterations, initial_temperature, cooling_rate):
    current_solution = initial_solution
    current_cost = cost_function(*current_solution)
    best_solution = current_solution
    best_cost = current_cost
    temperature = initial_temperature

    for _ in range(max_iterations):
        neighbor_solution = generate_neighbor(current_solution, temperature)
        neighbor_cost = cost_function(*neighbor_solution)

        # Accept the neighbor solution with a certain probability
        if random.uniform(0, 1) < acceptance_probability(current_cost, neighbor_cost, temperature):
            current_solution = neighbor_solution
            current_cost = neighbor_cost

        # Update the best solution if the current solution is better
        if current_cost < best_cost:
            best_solution = current_solution
            best_cost = current_cost

        # Cool the temperature
        temperature *= cooling_rate

    return best_solution, best_cost


# Example usage:
initial_solution = [4.0, 4.0]
max_iterations = 60
initial_temperature = 100.0
cooling_rate = 0.84

best_solution, best_cost = simulated_annealing(
    initial_solution, max_iterations, initial_temperature, cooling_rate)

print("Best Solution:", best_solution)
print("Best Cost:", best_cost)
