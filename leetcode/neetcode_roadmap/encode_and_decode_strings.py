class Codec:
    def encode(self, strs: list[str]) -> str:
        """Encodes a list of strings to a single string.
        """
        return '不'.join(strs)

    def decode(self, s: str) -> list[str]:
        """Decodes a single string to a list of strings.
        """
        return s.split('不')


codec = Codec()

strs = ["Hello","World"]
print(codec.decode(codec.encode(strs)))
