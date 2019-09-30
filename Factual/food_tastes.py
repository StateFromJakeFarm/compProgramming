def solution(inputTable):
    # Get unique city names and food foods and sum different food
    # foods for each city
    cities = []
    foods = []
    data = {}
    for row in inputTable:
        city, food, num = row

        cities.append(city)
        foods.append(food)

        num = int(num)
        if city not in data:
            data[city] = {food: num}
        elif food not in data[city]:
            data[city][food] = num
        else:
            data[city][food] += num

    # Use unique city and food names in lexicographical order
    cities = sorted(set(cities))
    foods = sorted(set(foods))

    # Convert to 2-D list data structure
    output = []
    for city in cities:
        row = []
        for food in foods:
            if food in data[city]:
                row.append(data[city][food])
            else:
                row.append(0)

        output.append(row)

    return output

print(solution([["Boston", "Mexican", "163"],
 ["Boston", "Seafood", "194"],
 ["Los Angeles", "American", "1239"],
 ["Los Angeles", "Mexican", "1389"],
 ["Los Angeles", "Seafood", "456"]]))
