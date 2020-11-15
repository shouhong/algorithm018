### 第四周学习笔记

#### 深度优先搜索模版（用递归）

```
visited = set() 
def dfs(node): 
  visited.add(node) 
  process(node) 
  for next_node in node.children(): 
    if not next_node in visited: 
      dfs(next_node)
```

#### 广度优先搜索模版（用队列）

```
def BFS(start): 
  queue = [] 
  queue.append(start) 
  visited.add(start) 
  while queue: 
    node = queue.pop() 
    process(node) 
    for next_node in node.children(): 
      if not next_node in visited: 
        visited.add(next_node) 
        queue.push(next_node)
```

#### 贪心算法
1. **最优子结构**：问题能够分解成子问题来解决，子问题的最优解能递推到最终问题的最优解。这种子问题最优解称为最优子结构。

2. **贪心算法与动态规划的区别**：贪心算法对每个子问题根据当下最优做出选择。动态规划则会保存以前的运算结果，并根据以前的结果对当前进行选择。

#### 二分查找
1. 二分查找的前提
	* 目标函数单调性（单调递增或者递减）
	* 存在上下界（bounded）
	* 能够通过索引访问（index accessible)

2. 二分查找模版

```
left, right = 0, len(array) - 1
while left <= right:
  mid = (left + right) / 2
  if array[mid] == target: # find the target!! 
    break or return result 
  elif array[mid] < target:
    left = mid + 1
  else:
    right = mid - 1
``` 