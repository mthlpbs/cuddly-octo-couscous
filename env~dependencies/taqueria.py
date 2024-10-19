import sys

def main() :
    TotalValue = 0.00
    itemName = " "
    while True :
        try :
            itemName = (input("Item: ")).strip().lower()
            item = foodItem()
            if not itemName:
                break
            if itemName in item :
                    TotalValue = total(item[itemName],TotalValue)
            else:
                pass

        except EOFError:
            break

def foodItem():
    item = {
                "baja taco": 4.25,
                "burrito": 7.50,
                "bowl": 8.50,
                "nachos": 11.00,
                "quesadilla": 8.50,
                "super burrito": 8.50,
                "super quesadilla": 9.50,
                "taco": 3.00,
                "tortilla salad": 8.00
            }
    return item

def total(x,y):
    y += float(x)
    print(f"Total:${y:.2f}")
    return y

if __name__ == "__main__":
    main()
