# https://leetcode.com/problems/duplicate-emails/description/

import pandas as pd

def duplicate_emails(person: pd.DataFrame) -> pd.DataFrame:
    counts = person.groupby('email').size()
    duplicates = counts[counts > 1].index.tolist()
    result = pd.DataFrame({'Email': duplicates})
    
    return result

