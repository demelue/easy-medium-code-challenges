class Codec:

    def encode(self, strs):
        """Encodes a list of strings to a single string.

        :type strs: List[str]
        :rtype: str
        """
        encodedString = list()
        header = 'H'
        endMarker = '*'
        i = 0
        for x in strs:
            encodedString.append(header + x + endMarker)

        return encodedString

    def decode(self, s):
        """Decodes a single string to a list of strings.

        :type s: str
        :rtype: List[str]
        """
        output = list()
        marker  = 0
        for x in s:
            if (x[0] == 'H'):
                if (x[-1] == '*'):
                    output.append(x[1:-1])
                else:
                    print("Bad String")
        return output

if __name__ == '__main__':
    codec = Codec()
    print(codec.decode(codec.encode(["63/Rc","h","BmI3FS~J9#vmk","7uBZ?7*/","24h+X","O "])))
