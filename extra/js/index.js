'use strict'

const rpc = require('sock-rpc')
const mongodb = require('mongodb')
const MongoClient = mongodb.MongoClient

const config = require('./config.json')

MongoClient.connect(config.url, {auto_reconnect: true}, (err, db) => {
  if (err) return console.error(err)
  console.info('Connected to DB')
  setupRpc(db)
})

// Registers RPC calls from ARMA
function setupRpc (db) {
  rpc.register('log', function () {
    var args = Array.prototype.slice.call(arguments, 0)
    var cb = args.pop()
    cb(null, true)

    if (!args || args.length < 4 || typeof args[3] !== 'string') return
    writeLog.apply(db, args)
  })

  rpc.listen(config.port || 1222)
}

// Writes log to DB
function writeLog (id, level, time, text) {
  // format text
  text = text.replace(/\[\"/g, '[')
  text = text.replace(/\"\]|\,\"\]/g, ']')
  text = text.replace(/\",\"/g, '')

  let q = {mission_id: id}
  let d = {
    $setOnInsert: {
      created_at: new Date().toISOString()
    },
    $push: {
      logs: {
        time,
        level,
        text
      }
    }
  }

  console.info('Writing log for mission %s', id)
  this.collection(config.collection).update(q, d, {
    upsert: true
  })
}
