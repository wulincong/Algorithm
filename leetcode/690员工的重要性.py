# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates

class Solution:
    def getEmployee(employees,id:int):
        for i in employees:
            if(i.id == id):
                return i 
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        Empl = Solution.getEmployee(employees,id)
        Sum = 0
        for j in Empl.subordinates:
            Sum += Solution.getEmployee(employees,j).importance
        return Empl.importance + Sum

if __name__ == '__main__':
    

