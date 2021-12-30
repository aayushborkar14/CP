years = {'Ox': 1, 'Tiger': 2, 'Rabbit': 3, 'Dragon': 4, 'Snake': 5, 'Horse': 6,
         'Goat': 7, 'Monkey': 8, 'Rooster': 9, 'Dog': 10, 'Pig': 11, 'Rat': 12}
years_list = ['', 'Ox', 'Tiger', 'Rabbit', 'Dragon', 'Snake',
              'Horse', 'Goat', 'Monkey', 'Rooster', 'Dog', 'Pig', 'Rat', 'Ox']
name_year = {'Bessie': 2000}


def get_zodiac(year):
    if year == name_year['Bessie']:
        return 'Ox'
    elif year > name_year['Bessie']:
        return years_list[(year - name_year['Bessie']) % 12 + 1]
    elif year < name_year['Bessie']:
        return years_list[13 - (name_year['Bessie'] - year) % 12]


n = int(input())
for i in range(n):
    statement = str(input())
    first_name = statement.split(' ')[0]
    previous = True if statement.split(' ')[3] == 'previous' else False
    year = statement.split(' ')[4]
    second_name = statement.split(' ')[7]
    if second_name == 'Bessie':
        if previous:
            name_year[first_name] = name_year[second_name] + years[year] - years[get_zodiac(name_year[second_name])]

# print(get_zodiac(1987))
# print(get_zodiac(1988))
# print(get_zodiac(2008))
# print(get_zodiac(2012))
# print(get_zodiac(2020))
