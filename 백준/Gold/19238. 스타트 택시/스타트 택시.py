import sys
from collections import deque

my_map = []
my_guest = []
direction = [[1,0], [-1,0], [0,1], [0,-1]]

def find_guest(sx, sy, n) :
    global my_guest
    queue = deque()
    queue.append([sx,sy,0])
    
    chk = [[] for _ in range(n)]

    for _ in range(n) :
        my_chk = []
        my_chk = [False for i in range(n)]
        chk[_] = my_chk

    chk[sx][sy]=True
    min_ = 5000
    min_x = 5000
    min_y = 5000

    while queue :
        x,y,count = queue.popleft()
        
        if count <= min_ and my_guest[x][y] :
            if min_x > x or (min_x == x and min_y > y) :
                min_x = x
                min_y = y
                min_ = count

        elif count > min_ :
            break

        for zx, zy in direction :
            zzx = x+zx
            zzy = y+zy

            if zzx < 0 or zzx >= n or zzy < 0 or zzy >=n or chk[zzx][zzy] or my_map[zzx][zzy]:
                continue

            chk[zzx][zzy] = True
            queue.append([zzx, zzy, count+1])
    
    if min_ < 5000 :
        return my_guest[min_x][min_y], min_
    else :
        return -1, -1

def bfs(sx, sy, fx, fy, n) :
    global my_map
    queue = deque()
    queue.append([sx,sy,0])
    
    chk = [[] for _ in range(n)]
    for _ in range(n) :
        my_chk = []
        my_chk = [False for i in range(n)]
        chk[_] = my_chk
        
    chk[sx][sy] = True

    while queue :
        x,y,count = queue.popleft()
        
        if x==fx and y==fy :
            return count

        for zx, zy in direction :
            zzx = x+zx
            zzy = y+zy

            if zzx < 0 or zzx >= n or zzy < 0 or zzy >=n or chk[zzx][zzy] or my_map[zzx][zzy]:
                continue

            chk[zzx][zzy] = True
            queue.append([zzx, zzy, count+1])

    return -1

def solution() :
    n, m, fuel = map(int, sys.stdin.readline().rstrip().split(' '))
    global my_map, my_guest

    my_map = [[] for _ in range(n)]
    my_guest = [[] for _ in range(n)]

    for _ in range(n):
        my_li = sys.stdin.readline().rstrip().split(" ")
        my_li = [int(i) for i in my_li]
        my_map[_] = my_li

        my_temp = [0 for i in range(n)]
        my_guest[_] = my_temp

    sx, sy = map(int, sys.stdin.readline().rstrip().split(' '))
    sx-=1
    sy-=1

    guest_arr = []
    guest_arr = [[] for _ in range(m)]
    flag = False

    for _ in range(m) :
        guest_temp = []
        guest_temp = [[] for _ in range(5)]
        guest_temp[0], guest_temp[1], guest_temp[2], guest_temp[3] = map(int, sys.stdin.readline().rstrip().split(' '))

        for i in range(4) :
            guest_temp[i]-=1
        
        guest_temp[4] = bfs(guest_temp[0], guest_temp[1], guest_temp[2], guest_temp[3], n)

        if guest_temp[4] == -1 :
            flag = True

        my_guest[guest_temp[0]][guest_temp[1]] = (_+1)
        guest_arr[_] = guest_temp

    if flag :
        fuel = -1
    else :
        for i in range(m) :
            point, charge = find_guest(sx,sy,n)

            if point == -1 and charge == -1 :
                fuel = -1
                break

            point -=1
            my_guest[guest_arr[point][0]][guest_arr[point][1]] = 0
            fuel = fuel - charge - guest_arr[point][4]
            
            if fuel < 0 :
                fuel = -1
                break
            else :
                fuel = fuel + guest_arr[point][4] * 2

            sx = guest_arr[point][2]
            sy = guest_arr[point][3]

    print(fuel)

solution()