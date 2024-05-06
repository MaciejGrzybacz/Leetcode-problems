# https://leetcode.com/problems/customers-who-never-order/description/

import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    merged = customers.merge(orders, how='left', left_on='id', right_on='customerId')
    no_orders = merged[merged['customerId'].isnull()]
    result = no_orders[['name']]
    result = result.rename(columns={'name' : 'Customers'})
    return result

