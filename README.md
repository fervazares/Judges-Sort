# Judges Sort
This program was our final projact for Computer Science 2. 
It was modeled after one of the problems in the ACM North America Southern California Regionals 2014.
Link to problem - https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=669&page=show_problem&problem=5101

In order to solve this problem I came up with the idea to take the scores from the judges as they came in and track their position along with the integer score inserted. I created a sort function that would sort them in ascending order based on score but also storing their initial position number. After that, a simple while statement compared the sorted arrays with one another based on position number. If the position numbers did not match, the while statement terminated and would print out the scores and positions after being sorted, and at which position the disagreement occured. 
