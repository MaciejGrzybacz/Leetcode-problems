# https://leetcode.com/problems/combine-two-tables/

import pandas as pd

def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    merged_frames=pd.merge(person,address,on='personId',how='left')
    merged_frames= merged_frames.drop(columns=['personId','addressId'])
    return merged_frames