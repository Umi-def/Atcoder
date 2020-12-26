static char ret = 0;
static int flag = 4;


char move_mychar(char grid)
{
    if(flag == 4){
        if(grid & 1 && grid & 8) {
            flag = 0; // 左上
            ret = 2;
            return 2;
        } else if(grid & 1 && grid & 2) {
            flag = 1; // 右上
            ret = 8;
            return 8;
        } else if(grid & 4 && grid & 8) {
            flag = 2; // 左下
            ret = 2;
            return 2;
        } else if(grid & 2 && grid & 4) {
            flag = 3; // 右下
            ret = 8;
            return 8;
        }
    }
    
    if(flag == 0 && grid == 3) {
        ret = 4;
        return 4;
    }
    if(flag == 1 && grid == 9) {
        ret = 4;
        return 4;
    }
    if(flag == 2 && grid == 6) {
        ret = 1;
        return 1;
    }
    if(flag == 3 && grid == 12) {
        ret = 1;
        return 1;
    }

    if(flag == 0 || flag == 1) {
        if((grid & 2 && ret == 2) || (grid & 8 && ret == 8)) {
            ret = 4;
            return 4;
        } else if (grid & 2 && ret == 4) {
            ret = 8;
            return 8;
        } else if(grid & 8 && ret == 4) {
            ret = 2;
            return 2;
        }
    }

    if(flag == 2 || flag == 3) {
        if((grid & 2 && ret == 2) || (grid & 8 && ret == 8)) {
            ret = 1;
            return 1;
        } else if (grid & 2 && ret == 1) {
            ret = 8;
            return 8;
        } else if(grid & 8 && ret == 1) {
            ret = 2;
            return 2;
        }
    }

    if(grid == 0 || grid == 1 || grid == 4) {
        return ret;
    }

    return 0;
}

char move_mychar_maze(char grid)
{
    static char dir = 0;

    if(flag == 4){
        flag = 0;
        dir = 1;
    }
    

    if(dir == 1) {
        dir = 8;
    } else {
        dir = dir >> 1;
    }

    while(grid & dir) {
        if(dir == 8) {
            dir = 1;
        } else {
            dir = dir << 1;
        }
    }
    
    return dir;
}