import pygame
import time

GREEN = (0, 255, 0)
BLACK = (0, 0, 0)

WIDTH = 800
HEIGHT = 700
BOX_SIZE = 20
SLEEP_TIME = 0.2

rows = WIDTH/BOX_SIZE
cols = HEIGHT/BOX_SIZE

states = [[0 for j in range(cols)] for i in range(rows)]

pygame.init()
clock = pygame.time.Clock()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption('GAME OF LIFE by BlueZ')


def init_states():

    while True:
        for event in pygame.event.get():

            if event.type == pygame.QUIT:
                pygame.quit()
                exit()

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    pygame.quit()
                    exit()

                if event.key == pygame.K_SPACE:
                    return

            if event.type == pygame.MOUSEBUTTONDOWN:
                mouse = pygame.mouse.get_pos()

                for i in range(1, rows-1):
                    for j in range(1, cols-1):
                        x = i * BOX_SIZE
                        y = j * BOX_SIZE
                        if mouse[0] in range(x, x+BOX_SIZE):
                            if mouse[1] in range(y, y+BOX_SIZE):
                                states[i][j] ^= 1

        screen.fill(BLACK)
        draw()
        pygame.display.flip()
        clock.tick(10)


def draw():
    for i in range(rows):
        for j in range(cols):
            if states[i][j] == 1:
                x = i * BOX_SIZE
                y = j * BOX_SIZE
                rect = pygame.Rect((x, y), (BOX_SIZE-2, BOX_SIZE-2))
                screen.fill(GREEN, rect)


def get_neighbours(i, j):
    count = 0
    for x in [-1, 0, 1]:
        for y in [-1, 0, 1]:
            if states[i+x][j+y] == 1:
                count += 1

    return count-states[i][j]


def calc_next_gen():

    global states
    states2 = [[0 for j in range(cols)] for i in range(rows)]

    for i in range(1, rows-1):
        for j in range(1, cols-1):
            n = get_neighbours(i, j)

            if states[i][j] == 0 and n == 3:
                states2[i][j] = 1

            if states[i][j] == 1:
                if n < 2 or n > 3:
                    states2[i][j] = 0
                else:
                    states2[i][j] = 1

    states = list(states2)


def main():

    done = False

    init_states()

    while not done:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                done = True
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    done = True

                if event.key == pygame.K_SPACE:
                    main()
                    return

        screen.fill(BLACK)

        calc_next_gen()
        draw()
        pygame.display.flip()

        time.sleep(SLEEP_TIME)
        clock.tick(60)

    pygame.quit()

if __name__ == '__main__':
    main()
