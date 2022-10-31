import numpy as np
import matplotlib.pyplot as plt
import sys
from matplotlib import animation


def init():
    line.set_data([], [])
    return line,


# animation function of dataframes' list
def animate_xy(i):
    line.set_data(xs[:i], ys[:i])

    # p = sns.lineplot(x=sx1, y=sy1,  color="r")

    # plt.setp(p.lines, linewidth=1)
    return line,


if __name__ == "__main__":
    path = sys.argv[1]
    xs = []
    ys = []
    with open(path, 'r') as file:
        for line in file.readlines():
            x, y = line.split()
            xs.append(int(x))
            ys.append(int(y))

    # print(min(xs))
    # plt.plot(xs, ys, marker='o')
    # plt.grid()
    # plt.show()

    fig = plt.figure()
    ax = plt.axes(xlim=(min(xs) - 1, max(xs) + 1), ylim=(min(ys) - 1, max(ys) + 1))
    ax.set_xticks(np.arange(min(xs)-1, max(xs)+1, 1))
    ax.set_yticks(np.arange(min(ys) - 1, max(ys) + 1, 1))
    plt.grid()
    line, = ax.plot([], [], lw=2, color='black', marker='o')
    anim = animation.FuncAnimation(fig, animate_xy,
                                   frames=len(xs), interval=250, blit=False)
    plt.show()
