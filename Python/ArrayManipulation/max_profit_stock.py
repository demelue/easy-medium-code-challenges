def max_profit_buying_stock(stock_prices):
    curr_max_profit = 0
    smallest_buy_price = max(stock_prices)
    j = 1
    for i in range(0, len(stock_prices)-1): #iterate to len - 1 because j starts at 1
        if (stock_prices[i] < stock_prices[j]):
            if stock_prices[i] < smallest_buy_price: #update buy price only when current prices is lower
                smallest_buy_price = stock_prices[i]
            curr_max_profit = stock_prices[j] - smallest_buy_price
        j += 1

    return curr_max_profit

def max_profit_shorting_stock(stock_prices):
    curr_max_profit = 0
    smallest_buy_price = min(stock_prices)
    j = 1
    for i in range(0, len(stock_prices)-1): #iterate to len - 1 because j starts at 1
        if (stock_prices[i] > stock_prices[j]):
            if stock_prices[i] > smallest_buy_price: #update buy price only when current prices is lower
                smallest_buy_price = stock_prices[i]
            curr_max_profit = stock_prices[j] - smallest_buy_price
        j += 1

    return curr_max_profit


if __name__=='__main__':
    prices = [8, 6, 5, 4, 3, 1]
    print("Maximum profit buying to sell: " + str(max_profit_buying_stock(prices)))
    prices = [2, 4, 5, 7, 1, 8, 9]
    print("Maximum profit shorting: " + str(abs(max_profit_shorting_stock(prices))))
