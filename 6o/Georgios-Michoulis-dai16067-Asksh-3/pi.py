from sys import argv, exit
from time import perf_counter
from math import pi as mathPi


def main(argv):

    numberOfSteps = argv

    try:
       numberOfSteps = int(numberOfSteps)

    except ValueError as e:
        print('Integer convertion error: {}' .format(e))
        exit(2)

    if numberOfSteps <= 0:
        print('Steps cannot be non-positive.')
        exit(3)

    t1 = perf_counter()

    pi = calcPi(numberOfSteps)

    t2 = perf_counter()

    print('Sequential program results with {} steps' .format(numberOfSteps))
    print('Computed pi = {}' .format(pi))
    print('Difference between estimated pi and math.pi = {}' .format(abs(pi - mathPi)))
    print('Time to compute = {} seconds' .format(t2-t1))


def calcPi(steps):
    """ Leibniz formula for arctan(1) = pi/4 """

    sum = 0
    step = 1.0 / steps

    for i in range(steps):
        x = (i + 0.5) * step
        sum += 4.0 / (1.0 + x**2)

    pi = sum * step

    return pi


if __name__ == '__main__':
    main(100000000)
