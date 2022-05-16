from audioop import reverse


class Node:
    def __init__(self,data,level,fval):
        self.data = data
        self.level = level
        self.fval = fval
    
    def generate_child(self):
        x,y = find(data,"_");

        val_list = [[x+1,y],[x-1,y],[y+1],[x,y-1]];

        children=[]

        for i in val_list:
            child = self.shuffle(self.data,x,y,i[0],i[1])
            children.append(child)

        return children
    
    def shuffle(self,puz,x,y,x1,y1):
        if(x1>=0 and x1<len(self.data) and y1>=0 and y1<len(slef.data)):
            temp_puz=[];
            temp_puz=self.copy(puz)

            temp=temp_puz[x1][y1]
            temp_puz[x1][y1]=temp_puz[x][y]
            temp_puz[x][y]=temp
        else:
            return None
    
    def copy(self,root):
        temp=[]
        for i in root:
            t = []
            for j in i:
                t.append[root[i][j]]
            temp.append(t)

        return temp

    def find(self,root,x):
        for i in range(0,len(self.data)):
            for j in range(0,len(self.data)):
                if(root[i][j]==x):
                    return i,j
                



class Puzzle:
    def __init__(self,size):
        self.n = size
        self.open = []
        self.closed = []

    def accept(self):
        temp = [];
        for i in range(self.size):
            t = input().split(" ");
            temp.append(t);
        return temp;
    
    def f(self,start,goal):
        return self.h(start.data,goal)+start.level
    
    def h(self,data,goal):
        ans = 0;
        for i in range(self.size):
            for j in range(self.size):
                if(dat[i][j]!=goal[i][j]):
                    ans=ans+1;
        return ans;
    
    def process():
        print("Enter the start value:\n")

        start = self.accept

        print("Enter the goal matrix:\n")

        goal = self.accept

        start = Node(start,0,0);

        start.fval = self.f(start,goal)

        self.open.append(start);

        while(true):
            cur = self.open[0];

            for i in cur.data:
                for j in i:
                    print(j,end=" " )
                print("")
            
            if( self.h(cur.data,goal)==0):
                break;
            
            for i in cur.generate_child():
                i.fval = self.f(i,goal)
                self.open.append(i)
            
            self.closed.append(cur)
            del self.open[0]

            self.open.sort(key=lambda x:x.fval,reverse=False)

puz = Puzzle(3)
puz.process()

