# https://leetcode.com/problems/employees-earning-more-than-their-managers/description/

import pandas as pd

def find_employees(employee: pd.DataFrame) -> pd.DataFrame:
    merged = pd.merge(employee, employee, left_on='managerId', right_on='id', suffixes=('_employee', '_manager'))
    result = merged[merged['salary_employee'] > merged['salary_manager']]
    result = result[['name_employee']]
    result.columns = ['Employee']
    return result
    