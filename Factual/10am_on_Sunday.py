import json

def solution(companies):
    '''
    Return how many businesses are open on Sundays before 10am
    '''
    def get_sunday_open_time(company):
        '''
        Return the hour portion of Sunday opening time as an integer
        '''
        sunday_hours = company['hours'].get('sunday')
        if sunday_hours is not None:
            return int(sunday_hours[0][0].split(':')[0])

        return None

    # Count number of companies fitting criteria
    num = 0
    for company in companies:
        data = json.loads(company)
        sunday_open_time = get_sunday_open_time(data)
        if sunday_open_time is not None and sunday_open_time < 10:
            num += 1

    return num

print(solution(["{\"hours\": {\"tuesday\": [[\"11:30\", \"23:00\"]], \"thursday\": [[\"11:30\", \"23:00\"]], \"wednesday\": [[\"11:30\", \"23:00\"]], \"friday\": [[\"11:30\", \"23:00\"]], \"sunday\": [[\"9:00\", \"23:00\"]], \"monday\": [[\"11:30\", \"23:00\"]], \"saturday\": [[\"11:30\", \"23:00\"]]}, \"name\": \"Yenny's Yard Supplies\"}"]))
