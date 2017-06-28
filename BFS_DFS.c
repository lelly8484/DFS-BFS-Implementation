
int depthsearch(int counterx, int countery, int *myarrayx, int*myarrayy, int **map, int startx1, int starty1, int endx1, int endy1)
{
    myarrayx[counterx]=startx1;
    myarrayy[countery]=starty1;
    int checkgoal = 0;

    

    if (map[starty1][startx1]==3)
    {
        for(int i=0; i<counterx; i++)
        {
            map[myarrayy[i]][myarrayx[i]]=5;
        }
        map[starty1][startx1]=5;
        return 1;
    }

    map[starty1][startx1]=4;

    if(map[starty1][startx1]!=3)
    {
        if (startx1<MAP_WIDTH-1)
        {
            if (map[starty1][startx1+1]==0||map[starty1][startx1+1]==3)
            {
                if (checkgoal!=1)
                {
                    map[starty1][startx1]=4;

                if(depthsearch(counterx+1, countery+1, myarrayx, myarrayy, map, startx1+1, starty1, endx1, endy1)==1)
                {
                    checkgoal=1;
                }
                }
            }
        }
        if (starty1<MAP_HEIGHT-1)
        {
            if(map[starty1+1][startx1]==0||map[starty1+1][startx1]==3)
            {
                if (checkgoal!=1)
                {
                    map[starty1][startx1]=4;

                if(depthsearch(counterx+1, countery+1, myarrayx, myarrayy, map, startx1, starty1+1, endx1, endy1)==1)
                {
                    checkgoal=1;
                }
                }
            }
        }
        if (startx1>0)
        {
            if(map[starty1][startx1-1]==0||map[starty1][startx1-1]==3)
            {
                if (checkgoal!=1)
                {
                    map[starty1][startx1]=4;

                if(depthsearch(counterx+1, countery+1, myarrayx, myarrayy, map, startx1-1, starty1, endx1, endy1)==1)
                {
                    checkgoal=1;
                }
                }
            }
        }
        if (starty1>0)
        {
            if(map[starty1-1][startx1]==0||map[starty1-1][startx1]==3)
            {
                if (checkgoal!=1)
                {
                    map[starty1][startx1]=4;

                if(depthsearch(counterx+1,countery+1, myarrayx, myarrayy, map, startx1, starty1-1, endx1, endy1)==1)
                {
                    checkgoal=1;
                }
                }
            }
        }
    }
    
    return checkgoal;
}

bool df_search(int **map)
{ 
	bool found = false;
	// PUT YOUR CODE HERE
	// access the map using "map[y][x]"
	// y between 0 and MAP_HEIGHT-1
	// x between 0 and MAP_WIDTH-1
    
    
    int startx=-1;
    int starty=-1;
    int endx;
    int endy;
    
    for (int i=0; i<MAP_WIDTH; i++)
    {
        for (int j=0; j<MAP_HEIGHT; j++)
        {
            if (map[j][i]==2)
            {
                startx=i;
                starty=j;
            }
            if (map[j][i]==3)
            {
                endx=i;
                endy=j;
            }
        }
    }
    
    if (startx!=-1&&starty!=-1)
    {
    int counterxx=0;
    int counteryy=0;
    int patharrayx[MAP_WIDTH*MAP_HEIGHT];
    int patharrayy[MAP_HEIGHT*MAP_WIDTH];
    if(depthsearch(counterxx, counteryy, patharrayx, patharrayy, map, startx,starty,endx,endy)==1)
    {
        found=true;
    }
    }
    
	return found;
}

int Data[MAP_WIDTH*MAP_HEIGHT*2];


int datab, datae;

void reset()
{
    datab=0;
    datae=0;
}

void add(int x,int y)
{
    Data[datae++]=x;
    Data[datae++]=y;
    /*
    Data[datae++]=prevx;
    Data[datae++]=prevy;
     */
}

bool get_first(int *x,int *y)
{
    if (datab==datae)
    {
        return false;
    }
    *x=Data[datab++];
    *y=Data[datab++];
    /*
    *prevx=Data[datab++];
    *prevy=Data[datab++];
     */
    return true;
}


int tracearrayx[MAP_WIDTH*MAP_HEIGHT*2];
int tracearrayy[MAP_HEIGHT*MAP_WIDTH*2];
int prevarray[MAP_HEIGHT*MAP_WIDTH*2];

int bfs(int **map, int startx1, int starty1)
{
    int tracecounter=-1;
    
    add(startx1,starty1);
    
    int x;
    int y;
    int prev;
    int mycounter=0;
    int tracker=-1;
    
    int tracer=0; 

    int checker9=0;
    
    prevarray[mycounter]=tracker;
    tracearrayx[mycounter]=startx1;
    tracearrayy[mycounter]=starty1;
    mycounter++;
    
    while(get_first(&x,&y))
    {
        
        
        if(map[y][x]==3)
        {
            
            
            while(map[tracearrayy[mycounter]][tracearrayx[mycounter]] !=3)
             {
                mycounter=mycounter-1;
            }
            
            while(prevarray[mycounter]!=-1)
            {
                map[tracearrayy[mycounter]][tracearrayx[mycounter]]=5;
                mycounter=prevarray[mycounter];
            }
            
            map[tracearrayy[mycounter]][tracearrayx[mycounter]]=5;
            
            return 1;
        }
        tracker++;
        map[y][x]=4;
        if (x<MAP_WIDTH-1)
            {
                if (map[y][x+1]==0||map[y][x+1]==3)
                {
                    prevarray[mycounter]=tracker;
                    tracearrayx[mycounter]=x+1;
                    tracearrayy[mycounter]=y;
                    mycounter++;
                    add(x+1, y);
                    
                }
            }
            if (y<MAP_HEIGHT-1)
            {
                if(map[y+1][x]==0||map[y+1][x]==3)
                {
                    prevarray[mycounter]=tracker;
                    tracearrayx[mycounter]=x;
                    tracearrayy[mycounter]=y+1;
                    mycounter++;
                    add(x, y+1);
                
                }
            }
            if (x>0)
            {
                if(map[y][x-1]==0||map[y][x-1]==3)
                {
                    prevarray[mycounter]=tracker;
                    tracearrayx[mycounter]=x-1;
                    tracearrayy[mycounter]=y;
                    mycounter++;
                    add(x-1,y);
                    
                }
            }
            if (y>0)
            {
                if(map[y-1][x]==0||map[y-1][x]==3)
                {
                    prevarray[mycounter]=tracker;
                    tracearrayx[mycounter]=x;
                    tracearrayy[mycounter]=y-1;
                    mycounter++;
                    add(x,y-1);
                }
            }

    }
    
    return 0;
}
bool bf_search(int **map)
{
	bool found = false;
	// PUT YOUR CODE HERE
	// access the map using "map[y][x]"
	// y between 0 and MAP_HEIGHT-1
	// x between 0 and MAP_WIDTH-1
    
    int startx=-1;
    int starty=-1;
    int endx;
    int endy;
    
    for (int i=0; i<MAP_WIDTH; i++)
    {
        for (int j=0; j<MAP_HEIGHT; j++)
        {
            if (map[j][i]==2)
            {
                startx=i;
                starty=j;
            }
            if (map[j][i]==3)
            {
                endx=i;
                endy=j;
            }
        }
    }
    reset();
    if (startx!=-1&&starty!=-1)
    {
    if(bfs(map, startx,starty)==1)
    {
        found=true;
    }
    }
    
	return found;
}
