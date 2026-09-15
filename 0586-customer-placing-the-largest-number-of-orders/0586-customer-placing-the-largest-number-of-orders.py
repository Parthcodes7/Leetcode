import pandas as pd

def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:
    result = orders["customer_number"].value_counts().idxmax()
    
    return pd.DataFrame({"customer_number": [result]})