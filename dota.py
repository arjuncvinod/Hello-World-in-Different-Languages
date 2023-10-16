from collections import deque
def solution(senate):
    Dq,Rq,l=deque(),deque(),len(senate)
    for i,c in enumerate(senate):
        Rq.append(i) if c=="R" else Dq.append(i)
    while Dq and Rq:
        d,r=Dq.popleft(),Rq.popleft()
        Dq.append(d+l) if d<r else Rq.append(r+l)
    return "Radiant" if Rq else "Dire"
print(solution(input("Enter string: ")))
