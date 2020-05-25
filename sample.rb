#input of int(split by space)
def get_i()
  return gets.chomp.split(" ").map(&:to_i)
end
#input of float(split by space)
def get_f()
  return gets.chomp.split(" ").map(&:to_f)
end
#input of string(split by space)
def get()
  return gets.chomp.split(" ")
end
#input of string(split per one character)
def get_nsp()
  return gets.chomp.split("")
end
#yes or no decision
def yn_judge(bool,y="Yes",n="No")
  return bool ? y : n 
end
#create of array
def array(size1,init=nil,size2=-1)
  if size2==-1
    return Array.new(size1){init}
  else
    return Array.new(size2){Array.new(size1){init}}
  end
end

def max(a,b)
    return a>b ? a : b
end

def min(a,b)
    return a>b ? b : a
end

INF=Float::INFINITY

class UnionFindTree
    attr_accessor:par,:rank
    def initialize(n)
        @par=Array.new(n){|i| i}
        @rank=array(n,0)
    end

    def find(x)
        return x if @par[x]==x
        @par[x]=find(@par[x])
        return @par[x]
    end

    def union(x,y)
        x=find(x)
        y=find(y)
        return if x==y
        if @rank[x]<@rank[y]
            @par[x]=y
        else
            @par[y]=x
            @rank[x]+=1 if @rank[x]==@rank[y]
        end
    end

    def same?(x,y)
        return find(x)==find(y)
    end
end
