var inspector = require('../index.js'),
    test = require('tap').test,
    http = require('http');

    console.log(inspector.inspect(http.createServer));
test(function (t) {
    var f = function foo() {
    };
    var res = inspector.inspect(f);
    t.ok(res.File.match(/01_simple.js/));
    t.equal(res.Name, 'foo');
    t.equal(res.InferredName, '');
    t.equal(res.LineNumber, 6);
    t.equal(res.ColumnNumber, 24);
    console.log(res);

    t.end();
});
