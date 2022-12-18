import re

from typing import List


class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        uniques = set()

        for email in emails:
            local, domain = email.split('@')
            local = re.sub('\+[a-z\.\+]*', '', local).replace('.', '')
            uniques.update([f'{local}@{domain}'])

        return len(uniques)


emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]

S = Solution()
print(S.numUniqueEmails(emails))
