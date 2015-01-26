class op_t(object):
    __slots__ = ('_value')

    name = 'tmwa::map::magic::op_t'
    depth = 1
    enabled = True

    def __init__(self, value):
        if not value:
            value = None
        self._value = value

    def to_string(self):
        value = self._value
        if value is None:
            return '(op_t *) nullptr'
        return '(op_t *)'

    def children(self):
        value = self._value
        if value is None:
            return
        value = value.dereference()
        yield '->name', value['name']
        yield '->signature', value['signature']
        yield '->op', value['op']

    test_extra = '''
    using tmwa::operator "" _s;
    '''

    tests = [
            ('static_cast<tmwa::map::magic::op_t *>(nullptr)',
                '(op_t *) nullptr'),
            ('new tmwa::map::magic::op_t{"name"_s, "sig"_s, nullptr}',
                '(op_t *) = {->name = "name", ->signature = "sig", ->op = nullptr}'),
    ]
