const path = require('path');

module.exports = {
  entry: {
    bundle: './lib/js/src/appRoot.js',
  },
  output: {
    path: path.join(__dirname, "bundledOutputs"),
    filename: '[name].js',
  },
};
