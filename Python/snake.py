import pygame
import collections
import time
import random

BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)

HEIGHT = 500
WIDTH = 600
BOX_SIZE = 25
INIT_SIZE = 6
FOOD_SIZE = 10

fps = 6
size = 0
rows = WIDTH/BOX_SIZE
cols = HEIGHT/BOX_SIZE

states = []

head = []
tail = []
head_dir = ''
tail_dir = ''
grow_pos = []
food_generated = False
deque = collections.deque()

pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
clock = pygame.time.Clock()


def init_game():
    global states
    global head
    global tail
    global head_dir
    global tail_dir
    global size
    global food_generated
    global fps

    states = [[0 for j in range(cols)] for i in range(rows)]

    while deque:
        deque.popleft()

    for x in range(INIT_SIZE):
        states[5+x][cols/2] = 1

    head = [5+INIT_SIZE-1, cols/2]
    tail = [5, cols/2]
    head_dir = 'right'
    tail_dir = 'right'
    size = INIT_SIZE
    fps = 6
    food_generated = False
    pygame.display.set_caption('SNAKE by BlueZ')


def game_over():
    global screen

    for count in range(8):
        if count % 2 == 0:
            draw()
        else:
            screen.fill(BLACK)
        pygame.display.flip()
        time.sleep(0.5)

    time.sleep(0.5)


def generate_food():
    global food_generated

    while not food_generated:
        i = random.randrange(0, rows)
        j = random.randrange(0, cols)
        if states[i][j] == 0:
            states[i][j] = 2
            food_generated = True


def move():
    global statues
    global tail_dir
    global size
    global grow_pos
    global food_generated
    global fps

    if head_dir == 'up':
        head[1] -= 1
    elif head_dir == 'down':
        head[1] += 1
    elif head_dir == 'left':
        head[0] -= 1
    elif head_dir == 'right':
        head[0] += 1

    if head[0] > rows-1:
        head[0] = 0
    elif head[0] < 0:
        head[0] = rows-1
    elif head[1] > cols-1:
        head[1] = 0
    elif head[1] < 0:
        head[1] = cols-1

    if states[head[0]][head[1]] == 0:
        states[head[0]][head[1]] = 1
    elif states[head[0]][head[1]] == 2:
        size += 1
        grow_pos = [head[0], head[1]]
        states[head[0]][head[1]] = 1
        food_generated = False
        pygame.display.set_caption('SCORE: ' + str(size - INIT_SIZE))
        if (size - INIT_SIZE) % 3 == 0:
            fps += 2
    else:
        game_over()
        init_game()
        return

    if grow_pos:
        if tail[0] == grow_pos[0] and tail[1] == grow_pos[1]:
            grow_pos = []
            return

    states[tail[0]][tail[1]] = 0

    if tail_dir == 'up':
        tail[1] -= 1
    elif tail_dir == 'down':
        tail[1] += 1
    elif tail_dir == 'left':
        tail[0] -= 1
    elif tail_dir == 'right':
        tail[0] += 1

    if tail[0] > rows-1:
        tail[0] = 0
    elif tail[0] < 0:
        tail[0] = rows-1
    elif tail[1] > cols-1:
        tail[1] = 0
    elif tail[1] < 0:
        tail[1] = cols-1

    if deque:
        info = deque[0]
        if tail[0] == info[0] and tail[1] == info[1]:
            tail_dir = info[2]
            deque.popleft()


def draw():
    for i in range(rows):
        for j in range(cols):
            if states[i][j] == 1:
                x = i * BOX_SIZE
                y = j * BOX_SIZE
                rect = pygame.Rect((x, y), (BOX_SIZE-2, BOX_SIZE-2))
                screen.fill(WHITE, rect)
            elif states[i][j] == 2:
                x = i * BOX_SIZE
                y = j * BOX_SIZE
                food_x = x+BOX_SIZE/2-FOOD_SIZE/2
                food_y = y+BOX_SIZE/2-FOOD_SIZE/2
                rect = pygame.Rect((food_x, food_y), (FOOD_SIZE, FOOD_SIZE))
                screen.fill(RED, rect)


def main():
    global head_dir
    done = False

    init_game()

    while not done:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                done = True

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    done = True

                if event.key == pygame.K_UP and head_dir != 'down':
                    head_dir = 'up'
                    info = [head[0], head[1]]
                    info.append('up')
                    deque.append(info)

                if event.key == pygame.K_DOWN and head_dir != 'up':
                    head_dir = 'down'
                    info = [head[0], head[1]]
                    info.append('down')
                    deque.append(info)

                if event.key == pygame.K_LEFT and head_dir != 'right':
                    head_dir = 'left'
                    info = [head[0], head[1]]
                    info.append('left')
                    deque.append(info)

                if event.key == pygame.K_RIGHT and head_dir != 'left':
                    head_dir = 'right'
                    info = [head[0], head[1]]
                    info.append('right')
                    deque.append(info)

        move()
        screen.fill(BLACK)

        if not food_generated:
            generate_food()

        draw()
        pygame.display.flip()

        clock.tick(fps)

    pygame.quit()


if __name__ == '__main__':
    main()
