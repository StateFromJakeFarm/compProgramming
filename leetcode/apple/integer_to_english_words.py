class Solution:
    def threeOrLess(self, num):
        digit_names = {
            '1': 'One',
            '2': 'Two',
            '3': 'Three',
            '4': 'Four',
            '5': 'Five',
            '6': 'Six',
            '7': 'Seven',
            '8': 'Eight',
            '9': 'Nine'
        }

        teens_names = {
            '10': 'Ten',
            '11': 'Eleven',
            '12': 'Twelve',
            '13': 'Thirteen',
            '14': 'Fourteen',
            '15': 'Fifteen',
            '16': 'Sixteen',
            '17': 'Seventeen',
            '18': 'Eighteen',
            '19': 'Nineteen'
        }

        tens_names = {
            '2': 'Twenty',
            '3': 'Thirty',
            '4': 'Forty',
            '5': 'Fifty',
            '6': 'Sixty',
            '7': 'Seventy',
            '8': 'Eighty',
            '9': 'Ninety'
        }

        idx = 0
        words = []
        if len(num) == 3:
            if num[idx] != '0':
                # Handle hundred
                words.extend([digit_names[ num[idx] ], 'Hundred'])

            idx += 1

        if len(num) >= 2:
            # Handle tens
            if num[idx] == '1':
                # Teens are special case
                words.append(teens_names[ num[idx:] ])

                return words
            elif num[idx] == '0':
                # Pass-through if there is a zero
                pass
            else:
                words.append(tens_names[ num[idx] ])

            idx += 1

        # Handle ones
        if num[idx] != '0':
            words.append(digit_names[ num[idx] ])

        return words


    def numberToWords(self, num: int) -> str:
        if num == 0:
            return 'Zero'

        num = str(num)

        commas = [
            'Thousand',
            'Million',
            'Billion'
        ]

        chunks = []
        for comma, i in enumerate(range(len(num), 0, -3)):
            chunk = num[max(0, i-3):i]
            chunks.append((chunk, comma))

        words = []
        for chunk, comma in reversed(chunks):
            chunk_words = self.threeOrLess(chunk)
            words.extend(chunk_words)
            if (len(chunk_words) > 0) and (comma > 0):
                words.append(commas[ comma-1 ])

        return ' '.join(words)


num = 3_110_483_647

S = Solution()

print(S.numberToWords(num))
