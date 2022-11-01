import sys
import matplotlib.pyplot as plt
# from PIL import Image
import numpy as np


def draw(xs: list, ys: list):
    # img = Image.fromarray(np.asarray(Image.open(file_input))[:, :, 2]) 
    plt.figure(figsize=(8, 8))
    plt.title("Best way", fontsize=20)
    # plt.imshow(img)
    plt.plot(xs[::-1], [abs(i) for i in ys[::-1]], c='r')
    plt.grid(True)
    plt.show()
    # plt.savefig(file_output)


def main():
    path = sys.argv[1]
    xs = []
    ys = []
    with open(path, 'r') as file:
        for line in file.readlines():
            x, y = line.split()
            xs.append(int(x))
            ys.append(int(y))
    # path = '..\path.txt'
    # xs, ys = [], []

    draw(xs, ys)


if __name__ == "__main__":
    main()
