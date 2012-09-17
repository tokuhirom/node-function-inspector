var inspector = require('../index.js'),
    test = require('tap').test;

test(function (t) {
    var res = inspector.inspect(inspector.inspect);

    t.equal(res.File, undefined);
    t.equal(res.Name, '');
    t.equal(res.InferredName, '');
    t.equal(res.LineNumber, -1);
    t.equal(res.ColumnNumber, -1);

    t.ok(1);
    t.end();
});
