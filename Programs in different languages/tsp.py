import math

def findHamiltonianCycle(distance, visited, current_city, cities, count, cost, hamiltonian_cycle):


  if count == cities and distance[current_city][0] > 0:
    hamiltonian_cycle = min(hamiltonian_cycle, cost + distance[current_city][0])
    return hamiltonian_cycle

  for i in range(cities):
    if not visited[i] and distance[current_city][i] > 0:
      visited[i] = True
      hamiltonian_cycle = findHamiltonianCycle(distance, visited, i, cities, count + 1, cost + distance[current_city][i], hamiltonian_cycle)
      visited[i] = False

  return hamiltonian_cycle


def main():
  cities = int(input("Enter total number of cities: "))

  distance = [[0 for i in range(cities)] for j in range(cities)]

  for i in range(cities):
    for j in range(cities):
      distance[i][j] = float(input("Distance from city {} to city {}: ".format(i + 1, j + 1)))

  visited = [False for i in range(cities)]
  visited[0] = True

  hamiltonian_cycle = math.inf

  hamiltonian_cycle = findHamiltonianCycle(distance, visited, 0, cities, 1, 0, hamiltonian_cycle)

  print(hamiltonian_cycle)


if __name__ == "__main__":
  main()
