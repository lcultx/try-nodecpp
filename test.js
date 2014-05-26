var addon = require('./build/Release/hello');

console.log(addon.hello());

var cb_addon = require('./build/Release/callback');
cb_addon(function(msg){
  console.log(msg);
});
