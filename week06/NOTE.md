### 第六周学习笔记

#### 递归模版

```
void recur(int level, int param) {
  // 递归结束条件 
  if (level > MAX_LEVEL) {
     // 处理结果 
     return; 
   }
  
  // 处理当前层逻辑 
  process(level, param);
  
  // 进入下一层 
  recur(level + 1, newParam);
  
  // 恢复当前层状态（如果进入下一层前修改了） 
}
```

#### 分治模版

```
result divide_conquer(problem, param1, param2, ...) {
  // 递归结束条件 
  if (问题小到能够直接求解) {
    generate_result()
    return result
  }
  
  // 问题拆分 
  data = prepare_data(problem) 
  subproblems = split_problem(problem, data) 

  // 通过递归调用解决子问题 
  subresult1 = divide_conquer(subproblems[0], p1, ...) 
  subresult2 = divide_conquer(subproblems[1], p1, ...) 
  subresult3 = divide_conquer(subproblems[2], p1, ...) 
  … 

  // 合并子问题的解
  result = process_result(subresult1, subresult2, subresult3, …) 

  // 恢复当前状态
}
```

#### 动态规划
1. 动态规划就是从前往后递推，与递归（从后往前）的方向相反。
2. 通常动态规划与递归+记忆化等效。
3. 动态规划步骤：
	* 定义状态（最关键的一步）
	* 推导状态转移方程（通常是从前面多个状态中分别推导出来，然后求最优值）
	* 计算初始值
	* 从初始值开始，按状态转移方程逐步递推导到最后
	* 最终结果可能是最后一个状态值，也可能是所有状态值中最优的那个。









